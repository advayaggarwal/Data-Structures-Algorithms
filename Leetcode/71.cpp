string simplifyPath(string path)
{
	//1. Tokenisation and Filtering - Find tokens separated by '/' and filter out . token and redundant forward slashes

	istringstream iss(path);
	vector<string>tokens;

	string token;

	while (getline(iss, token, '/'))
	{
		// We don't need "" and "." token as any multiple consecutive slashes (i.e. '//') are treated as a single slash
		// and a period '.' refers to the current directory, therefore both don't make any sense, we can ignore them
		if (token != "" and token != ".")	tokens.push_back(token);
	}


	//2. Handle ".." - Maintain a stack of tokens and when we encounter a ".." pop the top of the stack.

	vector<string>stack;

	if (path[0] == '/')
	{
		//denotes that our path is an absolute path (wrt root dir)
		stack.push_back("");
	}

	for (string token : tokens)
	{
		if (token == "..")
		{
			// 2 cases -> absolute path or relative path
			if (stack.size() == 0 or stack.back() == "..")
			{
				stack.push_back("..");
			}

			else if (stack.back() != "")	stack.pop_back(); //because of absolute path
		}

		else
		{
			stack.push_back(token);
		}
	}


	//3. Combine all the elements in stack to get the ans

	if (stack.size() == 1 and stack[0] == "")	return "/";

	ostringstream oss;
	int i = 0;
	for (auto token : stack)
	{
		if (i != 0)
		{
			oss << "/";
		}
		i++;
		oss << token ;
	}

	return oss.str();

}


string simplifyPath(string path)
{
	string res, tmp;
	vector<string> stk;
	stringstream ss(path);
	while (getline(ss, tmp, '/'))
	{
		if (tmp == "" or tmp == ".") continue;
		if (tmp == ".." and !stk.empty()) stk.pop_back();
		else if (tmp != "..") stk.push_back(tmp);
	}
	for (auto str : stk) res += "/" + str;
	return res.empty() ? "/" : res;
}
