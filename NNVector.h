NNVector :: NNVector(int n){
	// allocation only constructor
	size_var = n;
	arr = (float*)calloc(sizeof(float),size_var);
}
NNVector :: NNVector(int n, float *data){
	// allocate and initialize from integer pointer
	int i;
	size_var = n;
	arr = (float*)calloc(sizeof(float),n);
	for(i=0;i<size_var;i++){
		arr[i] = data[i];
	}
}
NNVector :: NNVector(NNVector &data){
	// allocate and initialize from integer pointer
	int i;
	size_var = data.size_var;
	arr = (float*)calloc(sizeof(float),size_var);
	for(i=0;i<size_var;i++){
		arr[i] = (data.arr)[i];
	}
}
NNVector :: NNVector(vector<float> data){
	// allocate and initialize from vector
	int i;
	size_var = data.size();
	arr = (float*)calloc(sizeof(float),size_var);
	for(i=0;i<size_var;i++){
		arr[i] = data[i];
	}
}
int NNVector :: size(){
	// get the size
	return size_var;
}
void NNVector :: setData(float *data){
	// set the vector with new data from pointer
	int i;
	for(i=0;i<size_var;i++){
		arr[i] = data[i];
	}
	return;
}
void NNVector :: setData(vector<float> data){
	// set the vector with new data from vector
	int i;
	for(i=0;i<size_var;i++){
		arr[i] = data[i];
	}
	return;
}
NNVector NNVector :: operator *(NNMatrix &data){
	// peform a multiplication of vector*matrix
	int i, j;
	int n = data.row; // equal to input count
	int m = data.col; // equal to output count
	assert(size_var==n); // needed for correct multiplication
	float new_arr[m];
	float s = 0;
	for(i=0;i<m;i++){
		s = 0.0;
		for(j=0;j<n;j++){
			s += arr[j]*(data.mat)[j][i];
		}
		new_arr[i] = s;
	}
	NNVector t(m, &new_arr[0]);
	t.print();
	getchar();
	return t;
}
float& NNVector :: operator [](int ind){
	// extract element at ind-th position
	return arr[ind];
}
void NNVector :: print(){
	// print the vector
	int i;
	printf("Size => %d\n",size_var);
	for(i=0;i<size_var;i++){
		printf(" %3f",arr[i]);
	}
	printf("\n");
	return;
}
