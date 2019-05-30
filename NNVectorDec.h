class NNVector{
	public:
	int size_var;
	float *arr;
	void *next;
	void *prev;
	public:
    NNVector(int n);
    NNVector(int n, float *data);
    NNVector(NNVector &data);
    NNVector(vector<float> data);
    int size();
    void setData(float *data);
    void setData(vector<float> data);
    NNVector operator *(NNMatrix &data);
    float& operator [](int data);
    void print();
};
