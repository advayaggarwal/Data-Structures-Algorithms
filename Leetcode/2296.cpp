#pragma GCC optimize("Ofast")
class TextEditor {
public:
    string t;
    int cursor;
    TextEditor() {
        cursor = 0;
    }

    void addText(string text) {
        int n = text.size();
        t.insert(cursor, text);
        cursor += n;
    }

    int deleteText(int k) {
        k = min(k, cursor);
        t.erase(cursor - k, k);
        cursor -= k;
        return k;
    }

    string cursorLeft(int k) {
        k = min(k, cursor);
        cursor -= k;
        int p = min(10, cursor);
        string ans = t.substr(cursor - p, p);
        return ans;
    }

    string cursorRight(int k) {
        k = min(k, (int)t.size() - cursor);
        cursor += k;
        int p = min(10, cursor);
        string ans = t.substr(cursor - p, p);
        return ans;
    }
};

//Using 2 stacks
/*
Always maintain the left part of string in left stack and right part of the string in right stack which are divided by the cursor

1) Add operation: Push string character by character to the left stack.
2) Deletion operation: Pop characters from the left stack and return the number of characters popped.
3) Cursor movement to left: Pop elements from left stack and push in right stack.
4) Cursor movement to right: Pop elements from right stack and push in left stack.
*/
class TextEditor {
public:
    stack<char> left, right; //left stores the chars to the left of cursor, and right stores the chars to the right of cursor
    TextEditor() {
    }

    void addText(string text) //O(n)
    {
        for (char c : text)   left.push(c);
    }

    int deleteText(int k) //O(k)
    {
        int count = 0;
        while (!left.empty() && k)
        {
            left.pop();
            count++;
            k--;
        }

        return count;
    }

    string cursorLeft(int k) //O(k)
    {
        while (!left.empty() && k--)
        {
            char c = left.top();
            left.pop();
            right.push(c);
        }

        return cursorShiftString();
    }

    string cursorRight(int k) //O(k)
    {
        while (!right.empty() && k--)
        {
            char c = right.top();
            right.pop();
            left.push(c);
        }

        return cursorShiftString();
    }

    string cursorShiftString() //O(10)
    {
        string output;
        int count = 10;
        while (!left.empty() && count--)
        {
            output += left.top();
            left.pop();
        }

        reverse(output.begin(), output.end());
        //Putting back to the left stack
        for (char c : output)    left.push(c);

        return output;
    }
};

//Using 2 strings as 2 stacks
class TextEditor {
public:
    string left, right; //left stores the chars to the left of cursor, and right stores the chars to the right of cursor
    TextEditor() {
    }

    void addText(string text) //O(n)
    {
        for (char c : text)   left.push_back(c);
    }

    int deleteText(int k) //O(k)
    {
        int count = 0;
        while (!left.empty() && k)
        {
            left.pop_back();
            count++;
            k--;
        }

        return count;
    }

    string cursorLeft(int k) //O(k)
    {
        while (!left.empty() && k--)
        {
            char c = left.back();
            left.pop_back();
            right.push_back(c);
        }

        return left.substr(left.size() - min((int)left.size(), 10));
    }

    string cursorRight(int k) //O(k)
    {
        while (!right.empty() && k--)
        {
            char c = right.back();
            right.pop_back();
            left.push_back(c);
        }

        return left.substr(left.size() - min((int)left.size(), 10));
    }
};