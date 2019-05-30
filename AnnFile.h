void NeuralNetwork :: save(string name){
    int i, j, k;
    int nameSize = name.length();
    char nameArr[nameSize+1];
    strcpy(nameArr,name.c_str());

    Layer *ptr = head;
	FILE *fptr = fopen(nameArr,"w");
	if(!fptr){
		printf("FILE CAN'T OPEN\n");
		getchar();
	}

	// write number of layers
	fprintf(fptr, "%d ", layer_count);
	// write number of neurons in each layer
	for(i=0;i<layer_count;i++){
		fprintf(fptr, "%d ", neuron_count[i]);
	}

	// write neuron count of current and next layer and weight matrix for that layer; do this for all blocks
	for(i=0;i<layer_count;i++){
		fprintf(fptr,"%d %d ",ptr->count,ptr->next_count);
		// write the matrix row by row
		for(j=0;j<ptr->count;j++){
			for(k=0;k<ptr->next_count;k++){
				fprintf(fptr, "%f ", ptr->wt[j][k]);
			}
		}
	}
	fclose(fptr);
	return;
}

NeuralNetwork NeuralNetwork :: load(string name, float (*member)(float a), float (*der)(float a)){
	int i, j, t, mx, row, col, *arr;
	int nameSize = name.length();
    char nameArr[nameSize+1];
    strcpy(nameArr,name.c_str());

	Layer *ptr = NULL;
	FILE *fptr = fopen(nameArr,"r");

	// get number of layers
	fscanf(fptr,"%d",&t);
	// get neuron count of all layers
	arr = (int*)calloc(sizeof(int),t);
	mx = 0;
	for(i=0;i<t;i++){
		fscanf(fptr,"%d",arr+i);
		mx = mx<arr[i]?arr[i]:mx;
	}

	// create object
	NeuralNetwork newNetwork(arr, t, member, der);
	free(arr);

	// create weight matrix
	float **wt;
	wt = (float**)calloc(sizeof(float*),mx);
	for(i=0;i<mx;i++){
		wt[i] = (float*)calloc(sizeof(float),mx);
	}

	// now start loading the weights
	ptr = newNetwork.head;
	while(ptr){
		fscanf(fptr,"%d %d", &row, &col);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				fscanf(fptr,"%f",wt[i]+j);
			}
		}
		ptr->wt.setData(wt);
	}
	fclose(fptr);
	return newNetwork;
}

void NeuralNetwork :: getTrainDataFromFormmattedMnistFile(string name, vector<vector<float> > &input, vector<vector<float> > &output){
    int nameSize = name.length();
    char nameArr[nameSize+1];
    strcpy(nameArr,name.c_str());

	FILE *fptr = fopen(nameArr, "r");
	if(!fptr){
		printf("FILE CAN'T OPEN\n");
		getchar();
	}

	char tmpChar;
	int i, j, t, data_size, in_size, out_size;
	fscanf(fptr,"%d %d %d",&data_size, &in_size, &out_size);
	printf("DATA_SIZE: %d, INPUT_COUNT: %d, OUTPUT_COUNT: %d\n", data_size, in_size, out_size);
	input.resize(data_size);
	output.resize(data_size);
	for(i=0;i<5;i++){
		input[i].resize(in_size);
		for(j=0;j<in_size;j++){
			fscanf(fptr,"%d",&t);
			input[i][j] = float(t);
		}
		output[i].resize(out_size);
		for(j=0;j<out_size;j++){
			fscanf(fptr,"%d",&t);
			output[i][j] = float(t);
		}
	}
	fclose(fptr);
	return;
}

void NeuralNetwork :: trainData(string name, float rate, int count, int epochs){
    int i, j, t, label;
    int nameSize = name.length();
    char nameArr[nameSize+1];
    strcpy(nameArr,name.c_str());

	FILE *fptr = fopen(nameArr, "r");
	if(!fptr){
		printf("FILE CAN'T OPEN\n");
		getchar();
	}
	char tmpChar;
	float **data;
	data = (float**)calloc(sizeof(float*),count);
	for(i=0; i<count; i++){
		data[i] = (float*)calloc(sizeof(float),head->count); // head count is the number inputs
		for(j=0; j< head->count; j++){
			fscanf(fptr,"%d",&t);
			data[i][j] = float(t);
		}
	}
	fclose(fptr);
	for(i=0;i<epochs;i++){
		for(j=0; j<count; j++){
			//learn(data[j]);
		}
	}
	return;
}
