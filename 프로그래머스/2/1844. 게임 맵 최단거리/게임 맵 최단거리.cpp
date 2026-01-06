#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
	int sizeY = maps.size();
	int sizeX = maps[0].size();

	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,-1,1 };

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	maps[0][0] = 1;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();

		int y = curr.first;
		int x = curr.second;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && ny < sizeY && nx >= 0 && nx < sizeX)
			{
				if (maps[ny][nx] == 1)
				{
					maps[ny][nx] = maps[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}

	int answer = maps[sizeY - 1][sizeX - 1];
	return (answer == 1) ? -1 : answer;
}