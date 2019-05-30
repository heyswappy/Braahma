NNMatrix :: NNMatrix(int n, int m){
	// n = row, m = column
	int i;
	row = n;
	col = m;
	mat = (float**)calloc(sizeof(float*),n);
	for(i=0;i<n;i++){
		mat[i] = (float*)calloc(sizeof(float),m);
	}
	next = prev = NULL;
}
NNMatrix :: NNMatrix(int n, int m, float **data){
	// initialize and setData from float pointer
	int i,j;
	row = n;
	col = m;
	mat = (float**)calloc(sizeof(float*),n);
	for(i=0;i<n;i++){
		mat[i] = (float*)calloc(sizeof(float),m);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat[i][j] = data[i][j];
		}
	}
	next = prev = NULL;
}
NNMatrix :: NNMatrix(NNMatrix &data){
	// initialize and setData from float vector
	int i,j,n,m;
	n = get<0>(data.size());
	m = get<1>(data.size());
	mat = (float**)calloc(sizeof(float*),n);
	for(i=0;i<n;i++){
		mat[i] = (float*)calloc(sizeof(float),m);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat[i][j] = data[i][j];
		}
	}
	next = prev = NULL;
}
NNMatrix :: NNMatrix(vector< vector<float> > data){
	// initialize and setData from float vector
	int i,j,n,m;
	n = data.size();
	m = data[0].size();
	mat = (float**)calloc(sizeof(float*),n);
	for(i=0;i<n;i++){
		mat[i] = (float*)calloc(sizeof(float),m);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat[i][j] = data[i][j];
		}
	}
	next = prev = NULL;
}
pair<int, int> NNMatrix :: size(){
	// return a pair of row, column
	pair<int, int> t(row, col);
	return t;
}
void NNMatrix :: setData(float **data){
	// set data from float pointer
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat[i][j] = data[i][j];
		}
	}
}
void NNMatrix :: setData(vector< vector<float> > data){
	// set data from float vector
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat[i][j] = data[i][j];
		}
	}
}
float* NNMatrix :: operator [](int ind){
	// extract i,j-th element
	return mat[ind];
}
void NNMatrix :: print(){
	// print from matrix
	int i,j;
	printf("Size => row: %d, col: %d\n",row,col);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf(" %3f",mat[i][j]);
		}
		printf("\n");
	}
	return;
}
