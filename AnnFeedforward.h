vector<float> NeuralNetwork :: input(vector<float> data){
	int i;
	NNVector inp(data);
	NNVector out(1);
	out = feedForward(inp);
	int n = out.size();
	vector<float> result(n);
	for(i=0;i<n;i++) result[i] = out[i];
	printf("RETURN FROM FEEDFORWARD\n");
	return result;
}

NNVector NeuralNetwork :: feedForward(NNVector data){
	printf("START FEEDOFRWARD\n");
	Layer *ptr = head;
	while(ptr){
		printf("NEXT LAYER\n");
		data = ptr->generate(data);
		printf("GENERATED\n");
		ptr = ptr->next;
	}
	printf("DONE FEEDFORWARD\n");
	return data;
}
float NeuralNetwork :: error(vector<float> error){
	Layer &ref = *last;
	int i;
	int n = ref.count;
	int e = 0;
	for(i=0;i<n;i++){
		e += (error[i]-ref.input[i])*(error[i]-ref.input[i]);
	}
	return e;
}

void NeuralNetwork :: compare(vector<float> label){
	// compare with labels
	Layer &ref = *last;
	int s = ref.count;
	float l = 0.0;
	for(int i=0; i<s; i++){
		printf("Activation: %d Label: %d\n",ref.activation[i],label[i]);
	}
}
