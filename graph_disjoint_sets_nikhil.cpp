// Non-directional graph
# include <iostream>
# include <vectors>
# include <queue>
# include <stack>
# include <assert>

using namespace std;

typedef int data_type;

struct graphNode
{
	data_type nodeValue;
	vector<graphNode*> links;
	graphNode(data_type in)
	{
		nodeValue = in;
	}
};

class graph
{	
	vector<graphNode> gnode;
	
	bool isPresent(vector<graphNode*>& qprint, graphNode* check)
	{
		for(int i = 0; i < qprint.size(); i++)
			if(check == qprint[i])
				return true;
		return false;
	}
public:
	void addNode(data_type in)
	{
		gnode.push_back(in);
	}
	
	int locate(data_type in)
	{
		for (int i = 0; i < gnode.size(); i++)
			if(in == gnode[i].nodeValue) return i;
		return -1;
	}
	
	bool isAdjacent (data_type a, data_type b)	// Checks if a is connected to b (directional)
	{
		int i = locate (a),j = locate (b);
		if ((i == -1) || (j == -1))
			return false;
		int k = 0;
		bool foundi = false, foundj = false;
		while (k < gnode[i].links.size() && (!foundi))
			if (gnode[i].links[k++] == &gnode[j]) 
				foundi = true;
		k = 0;
		while (k < gnode[j].links.size() && (!foundj))
			if (gnode[j].links[k++] == &gnode[i]) 
				foundj = true;
		
		return (foundi && foundj);
	}
	
	void printNeighbors (graphNode &a)
	{
		for (int i = 0; i < a.links.size(); i++)
			cout<<a.links[i]->nodeValue<<" ";
		cout<<endl;
	}
	
	void addEdge(graphNode& a, graphNode& b)
	{
		for (int i = 0; i < a.links.size(); i++)
			if(a.links[i] == &b)	// Assuming non directional graph
			{	
				cout<<"Already linked";
				return;
			}
		a.links.push_back(&b);
		b.links.push_back(&a);
	}
	
	void deleteEdge(graphNode& a, graphNode& b)
	{
		int i = 0, j = 0;
		bool foundi = false, foundj = false;
		while ((i < a.links.size()) && (!foundi))
			if(a.links[i] == &b)
			{	
				a.links.erase(a.links.begin()+i);
				foundi = true;
			}
			
		while ((j < b.links.size()) && (!foundj))
			if(b.links[j] == &a)
			{	
				b.links.erase(b.links.begin()+j);
				foundj = true;
			}
		if(!foundi && !foundj)	
			cout<<"Link not present";
	}
	
	graphNode* getFreeNode(const map<graphNode*, int> & mark)
	{
		for(map<graphNode*,int>::iterator i = mark.begin(); i< mark.end(); i++)
			if (i->second == 0) return (i->first);

		return NULL;
	}

	void dfs(graphNode* z, map<graphNode*, int> & mark, vector<graphNode*> &z)
	{
		if (mark[z]) return;

		mark[z]=true;
		Z.push_back(z);

		for(int i=0, i< (z->links).size(); i++)
			dfs((z->links)[i], mark, Z);

		return;
	}

	void printDisjointSets(vector<graphNode*> allNodes)
	{
		if (allNodes.empty()) return;

		map<graphNode*, bool> mark;
		vector<vector<graphNode*>> sets;

		for(int i=0;i < allNodes.size(); i++) mark[allNodes[i]] = 0; // Zero reprsents uninitilized

		while(1)
		{
			graphNode z = getFreeNode(mark);
			if (z==NULL) break;
			vector<graph_node*> Z;
			dfs(z, mark, Z);
			sets.push_back(Z);
		}

		for(int i=0;i<sets.size(); i++)
		{
			for(int j = 0; j < sets[i].size(); j++)
				cout<<sets[i][j]->nodeValue<<" ";
			cout<<endl;
		}
	}
};



/*
void graph::printBreadthFirst(graphNode* current)
{
	vector<graphNode*> mark;
	queue<graphNode*> nodeQueue;
	nodeQueue.push(current);
	mark.push_back(current);
	
	while(!nodeQueue.empty())
	{
		current = nodeQueue.front();
		nodeQueue.pop();
		for(int i = 0; i < current.links.size(); i++)
		{
			if(isPresent(mark,current.links[i]))
				continue;
			nodeQueue.push(current.links[i]);
			mark.push_back(current.links[i]);
		} 
	}
	cout<<"Printing graph breadth first:\n";
	for(int i = 0; i < mark.size(); i++)
		cout<<mark[i]->nodeValue<<" ";
	cout<<endl;
}

void graph::printDepthFirst(graphNode* current)
{
	vector<graphNode*> mark;
	stack<graphNode*> nodeStack;
	nodeStack.push(current);
	mark.push_back(current);
	
	while(!nodeStack.empty())
	{
		current = nodeStack.top();
		nodeQueue.pop();
		for(int i = 0; i < current.links.size(); i++)
		{
			if(isPresent(mark,current.links[i]))
				continue;
			nodeStack.push(current.links[i]);
			mark.push_back(current.links[i]);
		} 
	}
	cout<<"Printing graph depth first:\n";
	for(int i = 0; i < mark.size(); i++)
		cout<<mark[i]->nodeValue<<" ";
	cout<<endl;	
}

void shortestPath(graphNode* source, graphNode* destination)
{
	vector<graphNode*> mark, parent;
	queue<graphNode*> nodeQueue;
	graphNode* current = source;
	nodeQueue.push(current);
	mark.push_back(current);
	parent.push_back(NULL);
	
	bool found = false;
		
	while(!found && !nodeQueue.empty())
	{
		current = nodeQueue.front();
		nodeQueue.pop();
		
		for(int i = 0; i < current.links.size(); i++)
		{
			if(isPresent(mark,current.links[i]))
				continue;
			nodeQueue.push(current.links[i]);
			mark.push_back(current.links[i]);
			parent.push_back(current);
			if(current.links[i] == destination)
			{
				found = true;
				break;
			}	
		} 
	}
	if (found)
	{
		vector<graphNode*> path;
		graphNode* parentLookUp = destination;
		
		int i = mark.size()-1;
		while((parentLookUp != NULL) && i >= 0)
		{
			current = mark[i];
			if(current == parentLookUp)
			{
				path.push_back(current);
				parentLookUp = parent[i];
			}
			i--;
		}
		cout<<"Number of links = "<<path.size()-1<<endl;
		cout<<"shortest path is:\n";
		for(int i = path.size()-1; i >= 0; i--)	// Reading in reverse order
			cout<<path[i]->nodeValue<<" -> ";
		cout<<endl;
	}
	else
		cout<<"No path exists!\n";
}
*/