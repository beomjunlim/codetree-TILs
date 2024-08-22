#include <stdio.h>
#include <vector>

using namespace std;

#define MAX (100000 + 5000)
#define MAX_DEPTH (100 + 10)
#define MAX_COLOR (5)

#define ADD_NODE (100)
#define CHANGE_COLOR (200)
#define RETRIEVE_COLOR (300)
#define RETRIEVE_SCORE (400)

#define PARENT (1)

typedef struct st
{
	int id;
	int color;
	int maxDepth;
	int parent;
	vector<int> child;
}NODE;

NODE node[MAX];
int checkRoot[MAX];

int checkMakeChild(NODE cur, int depth)
{
	if (cur.id == 0) return 1; // 최대 깊이 이전에 부모를 찾은 경우
	if (cur.maxDepth <= depth) return 0;
	return checkMakeChild(node[cur.parent], depth + 1);
}

void addNode(int m_id, int p_id, int color, int max_depth)
{
	if (p_id == -1) checkRoot[m_id] = PARENT;

	if (checkRoot[m_id] == PARENT || checkMakeChild(node[p_id], 1))
	{
		node[m_id].id = m_id;
		node[m_id].color = color;
		node[m_id].maxDepth = max_depth;
		node[m_id].parent = checkRoot[m_id] == PARENT ? 0 : p_id;

		if (checkRoot[m_id] != PARENT)
			node[p_id].child.push_back(m_id);
	}
}

void dfs(int id, int color)
{
	node[id].color = color;

	for (int childId : node[id].child)
		dfs(childId, color);
}

void changeColor(int m_id, int color)
{
	dfs(m_id, color);
}

void retrieveColor(int m_id)
{
	printf("%d\n", node[m_id].color);
}

int calculate(NODE cur, int colorCount[])
{
	int tempColorCount[MAX_COLOR + 1] = { 0 };
	tempColorCount[cur.color] = 1;

	int sum = 0;
	for (int childId : cur.child)
	{
		NODE child = node[childId];

		int childColorCount[MAX_COLOR + 1] = { 0 };
		int score = calculate(child, childColorCount);

		for (int i = 1; i <= MAX_COLOR; i++) tempColorCount[i] += childColorCount[i];

		sum += score;
	}

	int count = 0;
	for (int i = 1; i <= 5; i++) count += !!tempColorCount[i];

	sum += (count * count);

	for (int i = 1; i <= MAX_COLOR; i++) colorCount[i] += tempColorCount[i];

	return sum;
}

int getScore()
{
	int score = 0;
	int colorCount[MAX_COLOR + 1] = { 0 };
	for (int i = 1; i <= 100000; i++)
		if (checkRoot[i] == PARENT)
			score += calculate(node[i], colorCount);

	return score;
}

void retrieveScore()
{
	int score = getScore();

	printf("%d\n", score);
}

int main()
{
	int Q;

	scanf("%d", &Q);

	for (int q = 0; q < Q; q++)
	{
		int COMMAND;

		scanf("%d", &COMMAND);

		if (COMMAND == ADD_NODE)
		{
			int m_id, p_id, color, max_depth;
			scanf("%d %d %d %d", &m_id, &p_id, &color, &max_depth);
			addNode(m_id, p_id, color, max_depth);
		}
		else if (COMMAND == CHANGE_COLOR)
		{
			int m_id, color;
			scanf("%d %d", &m_id, &color);
			changeColor(m_id, color);
		}
		else if (COMMAND == RETRIEVE_COLOR)
		{
			int m_id;
			scanf("%d", &m_id);
			retrieveColor(m_id);
		}
		else if (COMMAND == RETRIEVE_SCORE)
		{
			retrieveScore();
		}
	}

	return 0;
}