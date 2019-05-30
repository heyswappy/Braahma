#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<utility>
#include<string.h>
#include<cstring>
#include<assert.h>
#include<cmath>

#define SIGMOID NeuralNetwork::sigmoid
#define RELU NeuralNetwork::relu
#define SIGMOIDDER NeuralNetwork::sigmoidDer
#define RELUDER NeuralNetwork::reluDer
#define XAVIER NeuralNetwork::initXavier
#define MAX NeuralNetwork::maxMember
#define isDebug true

#include "declare.h"

int main(){
    int neurons[3] = {784,372,10};
    printf("NETWORK TO BE CREATED\n");
	NeuralNetwork obj(neurons, 3, RELU, RELUDER);
	printf("NETWORK CREATED\n");
	int i = 0;
	printf("LOADING FILE\n");
	vector<vector<float> > input, output;
	NeuralNetwork::getTrainDataFromFormmattedMnistFile("test.txt", input, output);
	cout<<"ABOUT TO TRAIN\n";
	getchar();
	for(int j=0; j<10; j++){
		printf("EPOCH COUNT: %d\n",j);

		for(int i=0;i<5;i++){
			printf("TRAINING SAMPLE NUMBER: %d\n",i);
			obj.input(input[i]);
			printf("ABOUT TO BACKPROPOGATE\n");
			obj.learn(input[i],output[i]);
			printf("BACKPROPOGATION DONE\n");

			printf("CHECKPOINT\n");
			//obj.finalizeWeight(0.5);
			//obj.save("networkMnist.txt");
		}
	}
	obj.save("networkMnist.txt");

	//----------------------------------------
	cout<<"ABOUT TO TEST=============================================\n";
	getchar();
	for(int i=0;i<1;i++){
		vector<float> ans = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
		ans[(int)input[0][0]] = 1.0; // label
		obj.input(input[0]);
		obj.compare(ans);
		getchar();
	}
	return 1;
}
