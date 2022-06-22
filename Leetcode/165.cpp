//Time complexity - O(m+n)
//Space complexity - O(m+n)
class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        istringstream ss(version1), iss(version2);

        vector<int>v1, v2;
        string v;
        while (getline(ss, v, '.'))   v1.push_back(stoi(v));
        while (getline(iss, v, '.'))   v2.push_back(stoi(v));
        int n1 = v1.size(), n2 = v2.size();

        int i = 0, j = 0;
        for (; i < n1 && j < n2; i++, j++)
        {
            if (v1[i] < v2[j])   return -1;
            else if (v1[i] > v2[j])  return 1;
        }

        while (i < n1)   if (v1[i++] != 0)  return 1;
        while (j < n2)   if (v2[j++] != 0)  return -1;

        return 0;
    }
};


//Time complexity - O(m+n)
//Space complexity - O(1)
class Solution {
public:
    int compareVersion(string v1, string v2)
    {
        int n1 = v1.size(), n2 = v2.size();
        int i = 0, j = 0;
        int num1 = 0, num2 = 0;
        while (i < n1 || j < n2)
        {
            while (i < n1 && v1[i] != '.')
            {
                num1 = num1 * 10 + (v1[i] - '0');
                i++;
            }

            while (j < n2 && v2[j] != '.')
            {
                num2 = num2 * 10 + (v2[j] - '0');
                j++;
            }

            if (num1 < num2) return -1;
            else if (num1 > num2)    return 1;

            num1 = num2 = 0;
            i++;
            j++;
        }

        return 0;
    }
};