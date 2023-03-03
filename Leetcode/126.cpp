//TLE
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> st (wordList.begin(), wordList.end());
        unordered_set<string> visited;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr_path = q.front();
                q.pop();
                string last = curr_path.back();
                for (int i = 0 ; i < last.size() ; ++i) {
                    auto temp = last;
                    for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                        temp[i] = ch;
                        if (st.find(temp) != st.end()) {
                            auto new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp);
                            if (temp == endWord)
                                ans.push_back(new_path);
                            else
                                q.push(new_path);
                        }
                    }
                }
            }
            for (auto& str : visited)
                st.erase(str);
        }
        return ans;
    }
};

class Solution {
public:
    bool neighbour(string a, string b) {
        int cnt = 0 ;
        for (int i = 0 ; i < a.length() ; i++)
        {
            if (a[i] != b[i])
            {
                cnt++ ;
            }
        }
        return cnt == 1 ;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);
        for (int i = 1 ; i < wordList.size() ; i++)
        {
            if (wordList[i] == wordList[0]) // string compare
            {
                wordList[i] = wordList.back() ;
                wordList.pop_back() ;
                break ;
            }
        }
        map<string, int> wti ; // word to index
        for (int i = 0 ; i < wordList.size() ; i++)
        {
            wti.insert({wordList[i], i}) ;
        }
        if (!wti.count(endWord))
        {
            return {} ;
        }
        vector<vector<int>> edges(wti.size()) ;
        for (int i = 0 ; i < wordList.size() ; i++)
        {
            for (int j = 0 ; j < wordList.size() ; j++)
            {
                if (i != j)
                {
                    if (neighbour(wordList[i], wordList[j]))
                    {
                        edges[i].push_back(j) ;
                    }
                }
            }
        }
        // BFS
        int start_node = 0 , target_node = wti[endWord] , r = 0 , min_step = INT_MAX ;
        vector<int> vis(wordList.size(), INT_MAX) ;
        vis[start_node] = 0 ;
        queue<int> q ;
        q.push(start_node) ;
        while (!q.empty())
        {
            int sz  = q.size() ;
            for (int i = 0 ; i < sz ; i++)
            {
                int fr = q.front() ;
                q.pop() ;
                if (fr == target_node)
                {
                    min_step = min(min_step , r) ;
                }
                for (int j = 0 ; j < edges[fr].size() ; j++)
                {
                    int update_node = edges[fr][j] ;
                    if (r + 1 < vis[update_node])
                    {
                        vis[update_node] = r + 1 ;
                        q.push(update_node);
                    }
                }
            }
            r++ ;
        }
        if (min_step == INT_MAX)
        {
            return {} ;
        }
        queue<vector<string>> q2 ;
        q2.push({wordList[target_node]}) ;
        r = min_step ;
        while (r)
        {
            int sz  = q2.size() ;
            for (int i = 0 ; i < sz ; i++)
            {
                vector<string> seq = q2.front() ;
                q2.pop();
                string back = seq.back() ;
                int curr = wti[back] ;
                for (int j = 0 ; j < edges[curr].size() ; j++)
                {
                    int new_node = edges[curr][j] ;
                    if (vis[new_node] == r - 1)
                    {
                        seq.push_back(wordList[new_node]) ;
                        q2.push(seq) ;
                        seq.pop_back() ;
                    }
                }
            }
            r-- ;
        }
        vector<vector<string>> ans;
        while (!q2.empty())
        {
            vector<string> temp = q2.front() ;
            q2.pop() ;
            reverse(begin(temp) , end(temp)) ;
            ans.push_back(temp) ;
        }
        return ans ;
    }
};

class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_map<string, unordered_set<string>>adj;
        unordered_set<string>words(wordList.begin(), wordList.end());

        queue<string>q;
        q.push(beginWord);

        unordered_map<string, int>visited;
        visited[beginWord] = 0;

        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            string temp = curr;

            for (int i = 0; i < curr.size(); i++)
            {
                for (char x = 'a'; x <= 'z'; x++)
                {
                    if (temp[i] == x)    continue;
                    temp[i] = x;

                    if (words.count(temp))
                    {
                        if (!visited.count(temp))
                        {
                            visited[temp] = visited[curr] + 1;
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if (visited[temp] == visited[curr] + 1)   adj[curr].insert(temp);
                    }
                }
                temp[i] = curr[i];
            }
        }

        vector<string>path;
        dfs(beginWord, endWord, adj, path);
        return ans;
    }

    void dfs(string beginWord, string endWord, unordered_map<string, unordered_set<string>>&adj, vector<string>&path)
    {
        path.push_back(beginWord);

        if (beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for (string nbr : adj[beginWord])
        {
            dfs(nbr, endWord, adj, path);
        }

        path.pop_back();
    }
};

class Solution {
public:
    bool able(string &a, string &b)
    {
        if (a.size() != b.size())    return false;
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
        {
            cnt += a[i] != b[i];
        }

        return cnt == 1;
    }

    void bfs(vector<vector<int>>&g, vector<int>parent[], int n, int sr, int ds)
    {
        vector<int>dist(n, 1005);
        queue<int>q;
        q.push(sr);
        parent[sr].push_back(-1);
        dist[sr] = 0;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (int u : g[x])
            {
                if (dist[u] > dist[x] + 1)
                {
                    dist[u] = dist[x] + 1;
                    q.push(u);
                    parent[u].clear();
                    parent[u].push_back(x);
                }

                else if (dist[u] == dist[x] + 1)   parent[u].push_back(x);
            }
        }
    }

    void shortestPaths(vector<vector<int>>&paths, vector<int>&path, vector<int>parent[], int node)
    {
        if (node == -1)
        {
            paths.push_back(path);
            return;
        }

        for (auto u : parent[node])
        {
            path.push_back(u);
            shortestPaths(paths, path, parent, u);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        int n = wordList.size(), sr = -1, ds = -1;
        vector<vector<string>>ans;

        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == beginWord)    sr = i;
            if (wordList[i] == endWord)  ds = i;
        }

        if (ds == -1)    return ans; //endWord not there in wordList, return empty {}
        if (sr == -1) //beginWord not there in wordList, so push beginWord to the start
        {
            wordList.emplace(wordList.begin(), beginWord);
            sr = 0; //src = 0;
            ds++; //dest index will increase by 1
            n++; //size of wordList will increase by 1
        }

        vector<vector<int>>g(n), paths;
        vector<int>parent[n], path;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (able(wordList[i], wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        bfs(g, parent, n, sr, ds);
        shortestPaths(paths, path, parent, ds);

        for (auto u : paths)
        {
            vector<string>now;
            for (int i = 0; i < u.size() - 1; i++)   now.push_back(wordList[u[i]]);
            reverse(now.begin(), now.end());
            now.push_back(wordList[ds]);
            ans.push_back(now);
        }

        return ans;
    }
};


class Solution {
public:
    // Create a map of type word->level to get the idea
    // on which level the word comes after the transformations.
    unordered_map<string, int> mpp; //{word, level}

    // A vector for storing the final answer.
    vector<vector<string>> ans;
    string b;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Perform BFS traversal and push the string in the queue
        // as soon as they’re found in the wordList.
        queue<string> q;
        b = beginWord;
        q.push({beginWord});

        // beginWord initialised with level 1.
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while (!q.empty())
        {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            // Break out if the word matches the endWord
            if (word == endWord)
                break;

            // Replace each character of the word with letters from a-z
            // and check whether the transformed word is present in the
            // wordList or not, if yes then push to queue
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {

                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word); //so that it's not visited again

                        // push the word along with its level
                        // in the map data structure.
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // If we reach the endWord, we stop and move to step-2
        // that is to perform reverse dfs traversal.
        if (mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }

    void dfs(string word, vector<string> &seq)
    {
        // Function for implementing backtracking using the created map
        // in reverse order to find the transformation sequence in less time.

        // Base condition :
        // If word equals beginWord, we’ve found one of the sequences
        // simply reverse the sequence and return.
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);

            // reverse again so that the dfs calls are not disturbed.
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word];

        // Replace each character of the word with letters from a-z
        // and check whether the transformed word is present in the map
        // and at the previous level or not.
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    // pop the current word from the back of the queue
                    // to traverse other possibilities.
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

};