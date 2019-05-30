float NeuralNetwork :: sigmoid(float t){
	t = 1/(1+exp(-t));
	return t;
}
float NeuralNetwork :: sigmoidDer(float t){
	t = NeuralNetwork::sigmoid(t);
	t = t*(1-t);
	if(isnan(t)) t=0;
	return t;
}
float NeuralNetwork :: relu(float t){
	(t<0)?t=0:t=t;
	return t;
}
float NeuralNetwork :: reluDer(float t){
	(t<0)?t=0:t=1;
	return t;
}
