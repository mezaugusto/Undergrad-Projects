# NTUST
# Homework #1
# Traveling Salesman Problem solved via state space search
# Author: Augusto Meza Peña
# Student ID: E10515019
# Date: 24 March 2017
# Notes: Must be runned in python3, graphviz package via pip required for graphic visualization

from graphviz import Digraph
from random import choice

class Node(object):
    def __init__(self, label):
        self.label = label

    def __str__(self):
        return str(self.label)

class Edge(object):
	def __init__(self,node1, node2, weight):
		self.node1 = node1
		self.node2 = node2
		self.weight = weight

	def containsPathForNodes(self,node1,node2):
		return (self.node1 == node1 and self.node2 == node2) or (self.node1 == node2 and self.node2 == node1)

class Graph(object):
	def __init__(self,nodes,edges):
		self.nodes = nodes
		self.unvisitedNodes = nodes
		self.edges = edges
		self.numNodes = len(nodes)
		self.numEdges = len(edges)
		self.verifyCompleteness()
		self.path,self.weight = self.hillClimbPath()
	def __str__(self):
		return "The graph path is: "+ self.pathToString(self.path) + " with a weight of: " + str(self.weight)

	def verifyCompleteness(self):
		if(self.numNodes < 2):
			print("Graph must contain at least 2 nodes")
		if( 0.5 * self.numNodes * (self.numNodes - 1) != self.numEdges ):
			print("Graph is not complete")
		edgesPairs = []
		for edge in self.edges:
			pair = edge.node1 , edge.node2
			reversePair = edge.node2 , edge.node1
			if(pair not in edgesPairs and reversePair not in edgesPairs):
				edgesPairs.append(pair)
			else:
				print("Edge between "+str(edge.node1)+" and "+str(edge.node2)+" is repeated")

	def pathToString(self,path):
		result = ''
		for node in path:
			result += str(node) + "->"
		return result + str(path[0])

	def getNextNode(self,initialNode,currentPath):
		nextNode = self.unvisitedNodes[0]
		minimalWeight = self.weightForNodes(initialNode,nextNode)
		for node in self.unvisitedNodes[1:]:
			if(self.weightForNodes(initialNode,node) < minimalWeight):
				nextNode = node
				minimalWeight = self.weightForNodes(initialNode,node)
		currentPath.append(nextNode)
		self.unvisitedNodes.remove(nextNode)
		if( len(self.unvisitedNodes) == 0):
			return currentPath
		return self.getNextNode(nextNode,currentPath)

	def hillClimbPath(self):
		initialNode = choice(self.nodes)
		print(initialNode)
		self.unvisitedNodes.remove(initialNode)
		path = self.getNextNode(initialNode,[initialNode])
		weight = self.weightWithPath(path)
		return path,weight

	def weightForNodes(self,node1,node2):
		for edge in self.edges:
			if(not edge.containsPathForNodes(node1,node2)):
				continue
			return edge.weight

	def weightWithPath(self,path):
		pathStack = list(path)
		weight = 0
		firstNode = pathStack.pop(0)
		while len(pathStack) > 0:
			node1 = pathStack.pop(0)
			node2 = firstNode if len(pathStack) == 0 else pathStack.pop(0)
			weight += self.weightForNodes(node1,node2)
		return weight

a = Node("A")
b = Node("B")
c = Node("C")
d = Node("D")
edge1 = Edge(a,b,2)
edge2 = Edge(b,c,7)
edge3 = Edge(c,d,5)
edge4 = Edge(d,a,9)
edge5 = Edge(a,c,1)
edge6 = Edge(d,b,7)
nodes = [a,b,c,d]
edges = [edge1,edge2,edge3,edge4,edge5,edge6]
example = Graph(nodes,edges)
print(example)
