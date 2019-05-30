void NeuralNetwork :: backpropogateStart(Layer &last, vector<float> label){
    int i, n;
    float delta = 0;
    float error = 0;
    n = last.count;
    printf("IN BACKPROPGATE NOW\n");
    for(i=0;i<n;i++){
        // (f(y_in) - t) * f'(y_in)
        delta = (last.activation[i] - label[i])*last.derivativeFunction(last.input[i]);
        error += delta;
    }
    for(i=0;i<n;i++){
        last.error[i] = error;
    }
    // compute wt change
    /*for(i=0;i<cur_layer.count;i++){
        // for each neuron in output
        row_error = 0;
        for(j=0;j<cur_layer.next_count;j++){
            // change = error * activation
            cur_layer.wt_change[i][j] += error*cur_layer.activation[i];
        }
    }*/
    return backpropogateRecurse(*(last.prev), last.error);
}

void NeuralNetwork :: backpropogateRecurse(Layer &cur_layer, NNVector &error){
    // for each neuron in input
    int i, j, row_error;
    printf("IN BACKPROPGATE RECURSIVE\n");
    for(i=0;i<cur_layer.count;i++){
        // for each neuron in output
        row_error = 0;
        for(j=0;j<cur_layer.next_count;j++){
            // error * w * f'(y_in)
            row_error += error[j]*cur_layer.wt[i][j]*cur_layer.derivativeFunction(cur_layer.input[i]);
        }
        cur_layer.error[i] = row_error;
    }
    // compute wt change
    for(i=0;i<cur_layer.count;i++){
        // for each neuron in output
        row_error = 0;
        for(j=0;j<cur_layer.next_count;j++){
            // change = error * activation
            cur_layer.wt_change[i][j] += error[j]*cur_layer.activation[i];
        }
    }
    printf("YP %u %u\n", &cur_layer, cur_layer.prev);
    if(cur_layer.prev == NULL){printf("EXITING"); return;}
    return backpropogateRecurse(*(cur_layer.prev), cur_layer.error);
}

bool NeuralNetwork :: learn(vector<float> input_vect, vector<float> label){
	samples++;
    input(input_vect);
    printf("ABOUT TO CALC ERROR\n");
    float e = error(label);
    printf("ERROR CALC DONE\n");
    if(e < 0.2){
        printf("START BACKPROPOGATE\n");
        backpropogateStart(*last, label);
        printf("BACKPROPOGATE DONE\n");
        return true;
    }
    return false;
}

void NeuralNetwork :: finalizeWeight(float alpha){
    int samples_worked_on = samples;
    int i, j, count, next_count;
    samples = 0; // reset
    Layer *ptr = last->prev;
    while(ptr){
            printf("DOING");
        count = ptr->count;
        next_count = ptr->next_count;
        NNMatrix &wt_change = ptr->wt_change;
        NNMatrix &wt = ptr->wt;
        for(i=0;i<count;i++){
            for(j=0;j<next_count;j++){
                wt[i][j] += alpha*wt_change[i][j];
                wt_change[i][j] = 0; // reset wt_change
            }
        }
    }
}
