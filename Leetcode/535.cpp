//Using increasing numbers as codes
class Solution {
public:
    unordered_map<string, string>m;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string ans = "http://tinyurl.com/" + to_string(num++);
        m[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return m[shortUrl];
    }
};

class Solution {
public:
    unordered_map<string, string> codeDB, urlDB;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    string getCode() {
        string code = "";
        for (int i = 0; i < 6; i++) code += chars[rand() % 62];
        return "http://tinyurl.com/" + code;
    }

    string encode(string longUrl) {
        if (urlDB.find(longUrl) != urlDB.end()) return urlDB[longUrl];
        string code = getCode();
        while (codeDB.find(code) != codeDB.end()) code = getCode();
        codeDB[code] = longUrl;
        urlDB[longUrl] = code;
        return code;
    }

    string decode(string shortUrl) {
        return codeDB[shortUrl];
    }
};

class Solution {
public:
    unordered_map<string, string>m;

    string encode(string longUrl)
    {
        string s;
        s.push_back(char(rand() % 128));

        while (m.count(s))
        {
            s.push_back(char(rand() % 128));
        }

        m[s] = longUrl;
        return s;
    }

    string decode(string shortUrl)
    {
        return m[shortUrl];
    }
};