#pragma once

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>


using namespace std;

template <typename T>
class CSC382Graph_Vertex
{
private:
	T data; // generic type variable
	list<CSC382Graph_Vertex<T>*>* connected_vertices; // list for connected vertices that is a generic type
public:
	//Constructor
	CSC382Graph_Vertex()
	{
		//initialize a new dynamic list
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		//data set to null
		data = NULL;
	}

	CSC382Graph_Vertex(T node_data)
	{
		//initialize a new dynamic list
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();
		//data set to data passed in
		data = node_data;
	}

	~CSC382Graph_Vertex()
	{
		//Delete the list
		delete connected_vertices;
	}


	void AddEdge(CSC382Graph_Vertex<T>* vertex_connection)
	{
		//If the list is not equal to this go into the if statement
		if (vertex_connection != this)
		{
			//push the passed in vertex into the list
			connected_vertices->push_back(vertex_connection);
		}
	}

	//Checkes if the the vertex got connected to the list
	bool VertexConnected(CSC382Graph_Vertex<T>* vertex_to_find)
	{
		//Check the whole list
		for(CSC382Graph_Vertex<T>* i : *connected_vertices)
		{
			//If the vertex is in the list
			if(i == vertex_to_find)
			{
				//return true
				return true;
			}
		}
		//if not return false
		return false;
	}

	//Remove the edge from the list
	void RemoveEdge(CSC382Graph_Vertex<T>* edge_to_remove)
	{
		//if the edge picked is not not a null pointer
		if (edge_to_remove != nullptr)
		{
			//Remove the edge
			connected_vertices->remove(edge_to_remove);
		}
	}

	//Get data inputed
	T GetData()
	{
		//return the data
		return data;
	}

	//Set the data
	void SetData(T data_param)
	{
		//Data equals the passed in data
		data = data_param;
	}

};


template <typename T>
class CSC382Graph_NodeBased
{
private:
	//list
	list<CSC382Graph_Vertex<T>*>* graph;

public:
	//constructor
	CSC382Graph_NodeBased()
	{
		//create a new dynamic list
		graph = new list<CSC382Graph_Vertex<T>*>;
	}


	CSC382Graph_NodeBased(CSC382Graph_Vertex<T>* initial_vertex)
	{
		//create a new dynamic list
		graph = new list<CSC382Graph_Vertex<T>*>;
		//insert the passe in vertex
		Insert(initial_vertex);
	}

	//deconstructor
	~CSC382Graph_NodeBased()
	{
		//for each into in the graph
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			//if it is not null or a null pointer
			if (iter != nullptr && iter != NULL)
			{
				//delete item from list
				delete iter;
			}
		}
		//delete list
		delete graph;
	}


	CSC382Graph_Vertex<T>* Insert(CSC382Graph_Vertex<T>* vertex)
	{
		//add the passed in vertex to the list
		graph->push_back(vertex);
		//return the vertex passed in
		return vertex;
	}


	CSC382Graph_Vertex<T>* Insert(T data)
	{
		//create a vertex and then add to list
		CSC382Graph_Vertex<T>* new_node = new CSC382Graph_Vertex<T>(data);
		//insert new vertex
		return Insert(new_node);
	}


	void RemoveVertex(T data)
	{
		//creae new vertex to remove and find it
		CSC382Graph_Vertex<T>* vertex_to_remove = FindVertex(data);
		//remove the vertex
		RemoveVertex(vertex_to_remove);
	}


	void RemoveVertex(CSC382Graph_Vertex<T>* vertex_to_remove)
	{
		//remove the vertex
		graph->remove(vertex_to_remove);
	}


	void AddEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		//Add an edge for the starting vertex and ending vertex
		start_vertex->AddEdge(end_vertex);
	}


	void RemoveEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)
	{
		//remove edge from starting vertex and ending vertex
		start_vertex->RemoveEdge(end_vertex);
	}


	bool IsEdge(CSC382Graph_Vertex<T>* vertex_to_search_in, CSC382Graph_Vertex<T>* edge_to_check_for)
	{
		//return if teh vertex to search for is connected to teh vertex it has to check for to ensure this is an edge
		return vertex_to_search_in->VertexConnected(edge_to_check_for);
	}

	//Find vertex
	CSC382Graph_Vertex<T>* FindVertex(T data_to_find)
	{
		//for each piece of data in the list
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			//Get the data and set it equal to parameter
			if (iter->GetData() == data_to_find)
			{
				//Return the data you are looking for
				return iter;
			}
		}
		//return null pointer
		return nullptr;
	}


	CSC382Graph_Vertex<T>* FindVertex(CSC382Graph_Vertex<T>* node_to_find)
	{
		//for each vertex in the list
		for(CSC382Graph_Vertex<T>* iter : *graph)
		{
			//set data to parameter
			if(iter == node_to_find)
			{
				//return vertex
				return iter;
			}
		}
		//return null pointer
		return nullptr;
	}


	int Size()
	{
		//return the size of the list
		return graph->size();
	}
};
