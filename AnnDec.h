class NeuralNetwork{
	public:
		int layer_count; // number of layers
		int *neuron_count; // array of neuron count in each layer
		int samples; // used while updating weightsin batches

		Layer *head;
		Layer *last;
		float (*membershipFunction)(float a);
		float (*derivativeFunction)(float a);
		int (*weightFunction)(Layer *node);
	public:
		// constructors
		NeuralNetwork(int *arr, int n, float (*ptr)(float t), float (*der)(float t));
		NeuralNetwork(NeuralNetwork &obj);
		// feedforward
		vector<float> input(vector<float> data);
		NNVector feedForward (NNVector data);
		float error(vector<float> error);
		void compare(vector<float> label);
		// membership
		static float sigmoid(float t);
		static float sigmoidDer(float t);
		static float relu(float t);
		static float reluDer(float t);
		// learning
		void backpropogateStart(Layer &last, vector<float> label);
		void backpropogateRecurse(Layer &cur_layer, NNVector &error);
		bool learn(vector<float> input_vect, vector<float> label);
		void finalizeWeight(float alpha);
		// file
		void save(string s);
		static NeuralNetwork load(string name, float (*ptr)(float t), float (*der)(float t));
		static void getTrainDataFromFormmattedMnistFile(string name, vector<vector<float> > &input, vector<vector<float> > &ouput);
		void trainData(string name, float rate, int count, int epochs);
};
