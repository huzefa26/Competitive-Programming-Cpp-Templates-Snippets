struct Trie
{
	int SZ = 26;
	struct Node
	{
		struct Node* child[SZ];
		bool stop;
		Node()
		{
			for(int i=0; i<SZ; i++)
				child[i] = nullptr;
			stop = false;
		}
	};
	Node* root;
	Trie ()
	{
		root = new Node();
	}
	void insert (string s)
	{
		Node* temp = root;
		for (auto c : s)
		{
			if (!temp->child[c-'a'])
				temp->child[c-'a'] = new Node();
			temp = temp->child[c-'a'];
		}
		temp->stop = true;
	}
	int getCount(Node* temp)
	{
		int cnt = 0;
		if (temp->stop)
			cnt++;
		for(int i=0; i<SZ; i++)
			if (temp->child[i])
				cnt += getCount(temp->child[i]);
		return cnt;
	}
	int count()
	{
		if (!root) return 0;
		return getCount(root);
	}
	bool search (string s)   // VERIFY THIS
	{
		Node* temp = root;
		for (auto c : s)
		{
			if (!temp)
				return false;
			temp = temp->child[c-'a'];
		}
		return (temp && temp->stop);
	}
};