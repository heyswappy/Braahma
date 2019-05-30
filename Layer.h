Layer :: Layer(int n, int m, float (*ptr)(float a), float (*der)(float a)):
activation(n) ,input(n), wt(n, m), wt_change(n, m), error(m){
    printf("CREATING LAYER WITH m:%d, n:%d\n",m,n);
	membershipFunction = ptr;
	derivativeFunction = der;
	count = n;
	next_count = m;
	prev = NULL;
	next = NULL;
}
void Layer :: establishConnections(){
    int i, j;
	for(i=0;i<count;i++){
		for(j=0;j<next_count;j++){
			wt.mat[i][j] = rand()%11;
		}
	}
}
void Layer :: establishConnections(float **mat){
	wt.setData(mat);
	return;
}
void Layer :: establishConnections(Layer* tmpLayer){
	wt = tmpLayer->wt;
	return;
}
NNVector Layer :: generate(NNVector data){
	input = data;
	if(prev==NULL) activation = data; // input layer
	else{
        int i;
        printf("-----%d %d",count,data.size());
		assert(count==data.size());
		for(i=0;i<count;i++){
			activation.arr[i] = membershipFunction(input[i]); // float to get copy of ref
		}
	}
	printf("GENERATE LAST\n");
	if(next==NULL) return activation; // output layer
	printf("GENERATE MID\n");
	data = (activation*wt);
	return data;
}
