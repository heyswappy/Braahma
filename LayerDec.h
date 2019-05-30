class Layer{
	public:
	int count;
	int next_count;
	NNVector input;
	NNVector activation;
	NNMatrix wt;
	NNMatrix wt_change;
	NNVector error;
	float (*membershipFunction)(float a);
	float (*derivativeFunction)(float a);
	Layer *next;
	Layer *prev;
	public:
	Layer(int n, int m, float (*ptr)(float a), float (*der)(float a));
	void establishConnections();
	void establishConnections(float **mat);
	void establishConnections(Layer *l);
	NNVector generate(const NNVector data);
};