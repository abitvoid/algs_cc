#include <stdio.h>
#include <math.h>
#include <string.h>
#include "kTree.h"



int main(int argc, char* argv[]){

	if(argc<2){
		fprintf(stderr,"USAGE: %s <GRAPH>\n",argv[0]);
		return(-1);
	}

	char *filename = (char *)malloc(sizeof(char)*(strlen(argv[1])+4));
	TREP * rep = loadTreeRepresentation(argv[1]);
	
  strcpy(filename,argv[1]);
  strcat(filename,".rb");
	FILE *fr = fopen(filename,"w");
	 fwrite(&(rep->numberOfNodes),sizeof(uint),1,fr);
  fwrite(&(rep->numberOfEdges),sizeof(uint),1,fr);

uint * listady, node, i, j, edge;
	//Sin usar rangos
	
//	for(i=0;i<rep->numberOfNodes;i++){
//  	listady = compact2AdjacencyList(rep, i);
//  	node = -(i+1);
//  	fwrite(&node,sizeof(uint),1,fr);
//  	for(j=0;j<listady[0];j++){
//  		edge = listady[j+1] + 1;
//  		fwrite(&edge,sizeof(uint),1,fr);
//  	}
//  }
//  
  //Usando check
  	uint ** listady2;
	for(i=0;i<rep->numberOfNodes;i++){
  	node = -(i+1);
  	fwrite(&node,sizeof(uint),1,fr);
		for(j=0;j<rep->numberOfNodes;j++){
			//fprintf(stderr,"(%d,%d)\n",i,j);
			//if((i==0)&&(j==24))
				//fprintf(stderr,"i: %d j: %d, check: %d\n",i,j,compactCheckLinkQuery(rep, i, j));
			if(compactTreeCheckLinkQuery(rep, i, j))	{
		  	edge = j + 1;
		  	fwrite(&edge,sizeof(uint),1,fr);
		  }
  	}
  }
  
  
  fclose(fr);
  
  destroyTreeRepresentation(rep);
  free(filename);
  
  return 0;
}


