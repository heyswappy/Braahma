class NNMatrix{
	public:
	int row;
	int col;
	float **mat;
	void *next;
	void *prev;
	public:
	NNMatrix(int m, int n);
	NNMatrix(int m, int n, float **data);
	NNMatrix(NNMatrix &data);
	NNMatrix(vector< vector<float> > data);
	pair<int, int> size();
	void setData(float **data);
	void setData(vector< vector<float> > data);
	float* operator [](int ind);
	void print();
};