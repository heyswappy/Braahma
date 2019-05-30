NeuralNetwork :: NeuralNetwork(int *arr, int n, float (*member)(float t), float (*der)(float t)){
	/* arr has he number of neurons in each layer
	n is the total number of layers i.e n-2 hidden layers */
	// assign function pointer
	int i;
	neuron_count = (int*)calloc(sizeof(int), n);

	for(i=0;i<n;i++){
		neuron_count[i] = arr[i];
	}

	membershipFunction = member;
	derivativeFunction = der;

	layer_count = n;
	head = new Layer(arr[0], arr[1], member, der);
	Layer *ptr = head;
	for(i=1; i<n; i++){
        cout<<i<<"\n";
		ptr->next = new Layer(arr[i], arr[i+1], member, der);
		ptr->next->prev = ptr;
		ptr = ptr->next;
	}
	// last layer; second argument same as first to facilitate for error gradients
	printf("CREATING LAST LAYER\n");
	ptr->next = new Layer(arr[i-1], arr[i-1], member, der);
	ptr->next->prev = ptr;
	last = ptr->next;
	ptr = ptr->next;
	return;
}
NeuralNetwork :: NeuralNetwork(NeuralNetwork &obj){
	// copy constructor
    int i, n;
    samples = obj.samples;
    layer_count = obj.layer_count;
    n = layer_count;
    head = new Layer(*(obj.head));
	Layer *ptr = head;
	Layer *ptr2 = obj.head;
	for(i=1; i<n-1; i++){
		ptr->next = new Layer(*ptr2);
		ptr->next->prev = ptr;
		last = ptr->next;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	// assign function pointer
	membershipFunction = obj.membershipFunction;
	derivativeFunction = obj.derivativeFunction;
	return;
}
