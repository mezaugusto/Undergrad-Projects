import csv
from random import choice
from math import sqrt,pow,isclose
import plotly.plotly as py
import plotly.graph_objs as go

def distance_between(pA,pB):
    return sqrt(pow(pA.x - pB.x, 2.0) + pow(pA.y - pB.y, 2.0))
class Point:
    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)
    def __str__(self):
        return "X:"+str(self.x)+" Y:"+str(self.y)+"\n"

class KmeansFrom:
    def __init__(self,fn,k):
        self.fn = fn
        self.points = self.obtainPoints()
        self.k = k
        self.clusters = dict()
        self.centroids = list()
        self.define_initial_clusters()


    def obtainPoints(self):
        points = list()
        with open(self.fn) as raw_data:
            for line in csv.reader(raw_data):
                points.append(Point(line[0], line[1]))
        return points

    def distanceFromClusters(self,point):
        mean = 0
        for i in range(0,len(self.clusters)):
            mean += distance_between(self.clusterCentroid(i),point)
        return mean/len(self.clusters)

    def clusterCentroid(self,k):
        centroidx = 0
        centroidy = 0
        for point in self.clusters[k]:
            centroidx += point.x
            centroidy += point.y
        return Point(centroidx/len(self.clusters[k]),centroidy/len(self.clusters[k]))

    def define_initial_clusters(self,i=0):
        if i == 0:
            self.clusters.update({i:[choice(self.points)]})
        else:
            next_point = None
            max_distance = 0
            for point in self.points:
                mean_distance = self.distanceFromClusters(point)
                if mean_distance > max_distance:
                    next_point = point
                    max_distance = mean_distance
            self.clusters.update({i: [next_point]})

        self.points.remove(self.clusters[i][0])
        if i+1 < self.k:
            self.define_initial_clusters(i+1)
            return
        self.assign_points()

    def empty_clusters(self):
        for i in self.clusters:
            self.clusters[i]=[]

    def assign_points(self,iter=0):
        centroids = list()
        for i in self.clusters:
            centroids.append([i,self.clusterCentroid(i)])
        if iter>0:
            self.empty_clusters()
        for point in self.points:
            min_distance = None
            cluster = None
            for centroid in centroids:
                distance = distance_between(centroid[1],point)
                if min_distance is None or distance < min_distance:
                    min_distance = distance
                    cluster = centroid[0]
            self.clusters[cluster].append(point)
        if len(self.centroids) == 0:
            self.centroids = centroids
            for centroid in centroids:
                self.points.append(centroid[1])
        elif self.same_centroids(centroids):
            return self.graph(iter)
        self.centroids = centroids
        self.assign_points(iter+1)
        return iter

    def same_centroids(self,new_centroids):
        same = True
        for centroid in self.centroids:
            if not isclose(new_centroids[centroid[0]][1].x,centroid[1].x) and not isclose(new_centroids[centroid[0]][1].y,centroid[1].y):
                same = False
        return same

    def graph(self,iter):
        data = []
        for i in self.clusters:
            cluster = self.clusters[i]
            trace = go.Scatter(
                x=[cluster[i].x for i in range(0,len(cluster))],
                y=[cluster[i].y for i in range(0,len(cluster))],
                mode="markers",
                marker=dict(
                    size=9,
                    line = dict(
                        width=2
                    )
                ),
                name="Cluster "+str(i+1)
            )
            data.append(trace)
            fig = dict(
                data=data,
                layout=dict(
                    title="K-means Classification Algorithm"
                )

            )
        py.plot(fig, filename='kmeans.png')


input_data_filename = "data.txt"
with_number_of_clusters = 3

KmeansFrom(input_data_filename,with_number_of_clusters)