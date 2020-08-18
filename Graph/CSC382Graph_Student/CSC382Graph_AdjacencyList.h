#pragma once
template <typename T>
class CSC382Graph_AdjacencyList
{
public:
	//Constructor
	CSC382Graph_AdjacencyList()
	{
		//dynamically create a new list
		graph_adjacencylist = new vector<list<T>*>();
	}
	//Deconstructor
	~CSC382Graph_AdjacencyList()
	{
		//cycle through the list
		for (list<T>* iter : *graph_adjacencylist)
		{
			//if the data is not a null pointer
			if (iter != nullptr)
			{
				//delete the data
				delete iter;
			}
		}
		//delete the list
		delete graph_adjacencylist;
	}

	list<T>* AddVertex(T data)
	{
		// Attempt to find
		if (IsVertex(data))
		{
			cout << "Vertex is already in the graph. Duplicate NOT added." << endl;
			return nullptr;
		}
		else
		{

			list<T>* new_vertex = new list<T>();		// Create new list to house the vertex and its edges
			new_vertex->push_back(data);				// Data is added as the first element in the list
			graph_adjacencylist->push_back(new_vertex);	// list pointer is added to the graph
			return new_vertex;
		}
	}

	bool AddEdge(list<T>* vertex, T data)
	{
		if(!IsVertex(vertex))
		{
			cout << "Vertex specified does not exist. Cannot add edge to a non-existant vertex."
			return false;
		}
		if (!IsVertex(data))		// Data must be an existing vertex or it will need to be created.
		{
			//add data to vertex
			vertex->push_back(data);
			return true;
		}
		else
		{
			//create list of new vertex and add vertex data 
			list<T>* new_vertex = AddVertex(data);
			new_vertex->push_back(data);
			return true;
		}
	}

	bool AddEdge(list<T>* starting_vertex, list<T>* ending_vertex)
	{
		//check to make sure vertex is in graph
		if(!IsVertex(starting_vertex) || !IsVertex(ending_vertex))
		{
			cout << "Cannot AddEdge because one of the specified vertices does not exist in the graph." << endl;
			return false;
		}
		if (!IsEdge(starting_vertex, ending_vertex->front()))		// Prevent adding duplicate edges
		{
			//add the edge
			starting_vertex->push_back(ending_vertex->front());
			return true;
		}
		return false;
	}

	bool IsVertex(T data)
	{
		//cycle through list
		for (list<T>* iter : *graph_adjacencylist)
		{
			// Check the first value in the list which is the primary vertex
			if (iter->front() == data)
			{
				return true;
			}
		}
		return false;
	}

	bool IsVertex(list<T>* vertex_to_find)
	{
		//cycle through list
		for (list<T>* iter : *graph_adjacencylist)
		{
			//if the data is the vertex to find
			if (iter == vertex_to_find)
			{
				//return true
				return true;
			}
		}
		return false;
	}

	bool IsEdge(T edge_to_find)
	{
		//cycle through list
		for (list<T>* iter : *graph_adjacencylist)
		{
			//check if it is an edge
			if (IsEdge(iter, edge_to_find))
			{
				return true;
			}
		}
		return false;
	}

	bool IsEdge(list<T>* vertex, T edge_to_find)
	{
		//cycle through list
		for (T i : *vertex)
		{
			// skip checking the primary vertex and only check edges
			if (vertex->front() == i)
			{
				continue;
			}
			//check if the data is the vertex we are looking for
			if (i == edge_to_find)
			{
				return true;
			}
		}
		return false;
	}

	list<T>* FindVertex(T data)
	{
		//cycle through list
		for (list<T>* iter : *graph_adjacencylist)
		{
			//if the data is found
			if (iter->front() == data)
			{
				//return the vertex
				return iter;
			}
		}
		return nullptr;
	}

	void PrintAdjacencyList()
	{
		//cycle through list
		for (list<T>* iter : *graph_adjacencylist)
		{
			//cycle through data
			for (T i : *iter)
			{
				// skip checking the primary vertex and only check edges
				if (iter->front() == i)		// Prints the Vertex 
				{
					cout << "Vertex = " << i << "   Edges = ";
				}
				else	// Prints the Edges
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}

	int NumberOfEdges(T vertex_data)
	{
		//new list to find the vertices
		list<T>* vertex = FindVertex(vertex_data);
		//check if the vertex is not a null pointer
		if(vertex != nullptr)
		{
			//return the number of edges found
			return NumberOfEdges(vertex);
		}
		return -1;
	}

	int NumberOfEdges(list<T>* vertex)
	{
		//return the number of vertices
		return vertex->size();
	}

	int GraphSize()
	{
		//return list size
		return graph_adjacencylist->size();
	}

private:
	//list adjacency list
	vector<list<T>*>* graph_adjacencylist;
};