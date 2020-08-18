#pragma once

template <typename T>
class CSC382Graph_Edge
{
private:
	CSC382Graph_Vertex<T>* starting_vertex;
	CSC382Graph_Vertex<T>* ending_vertex;
public:
	CSC382Graph_Edge()
	{
		starting_vertex = nullptr;
		ending_vertex = nullptr;
	}

	CSC382Graph_Edge(CSC382Graph_Vertex<T>* start, CSC382Graph_Vertex<T>* end)
	{
		starting_vertex = start;
		ending_vertex = end;
	}

	~CSC382Graph_Edge()
	{
		starting_vertex = nullptr;
		ending_vertex = nullptr;
	}
};