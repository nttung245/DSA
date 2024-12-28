#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Kiểm tra virus từ một vị trí cụ thể
bool checkVirus(const vector<string> &grid, const string &virus, int x, int y)
{
    int N = (int)grid.size();
    int M = (int)grid[0].size();
    int len = (int)virus.length();

    // Kiểm tra ngang
    if (y + len <= M)
    {
        bool match = true;
        for (int j = 0; j < len; j++)
        {
            if (grid[x][y + j] != virus[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return true;
    }

    // Kiểm tra dọc
    if (x + len <= N)
    {
        bool match = true;
        for (int i = 0; i < len; i++)
        {
            if (grid[x + i][y] != virus[i])
            {
                match = false;
                break;
            }
        }
        if (match)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    // Đọc grid
    vector<string> grid(N);

    // Hash map lưu vị trí các ký tự
    unordered_map<char, vector<pair<int, int>>> charMap;

    // Đọc grid và xây dựng hash map
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < M; j++)
        {
            charMap[grid[i][j]].push_back({i, j});
        }
    }

    // Xử lý truy vấn
    for (int q = 0; q < Q; q++)
    {
        string virus;
        cin >> virus;

        bool found = false;
        // Chỉ tìm kiếm từ các vị trí có ký tự đầu tiên của virus
        if (charMap.find(virus[0]) != charMap.end())
        {
            for (const auto &pos : charMap[virus[0]])
            {
                if (checkVirus(grid, virus, pos.first, pos.second))
                {
                    found = true;
                    break;
                }
            }
        }
        cout << found;
    }

    return 0;
}