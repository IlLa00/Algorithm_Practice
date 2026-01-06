#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int current_index, int sum, vector<int>& numbers, int target)
{
    if (current_index == numbers.size())
    {
        if (sum == target)
        {
            answer++;
        }
        return; 
    }

    dfs(current_index + 1, sum - numbers[current_index], numbers, target);
    dfs(current_index + 1, sum + numbers[current_index], numbers, target);
}

int solution(vector<int> numbers, int target) 
{
    dfs(0,0, numbers, target);


    return answer;
}