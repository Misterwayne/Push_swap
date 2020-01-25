import numpy as np 

def largest(arr,n): 
  
    # Initialize maximum element 
    max = arr[0] 
  
    # Traverse array elements from second 
    # and compare every element with  
    # current max 
    for i in range(1, n): 
        if arr[i] > max: 
            max = arr[i] 
    return max

def sigfunc(x):
    return 1 / (1 + np.exp(-x))

def sigfunc_derivative(x):
    return x * (1 - x)

exemple = np.array([[0,0,1],
                    [1,1,1],
                    [1,0,1],
                    [0,1,1]])

result = np.array([[0,1,1,0]]).T 

np.random.seed(6)

emo_value = 2 * np.random.random((3, 1))


print('Random starting emotial values :')

print(emo_value)

for iteration in range(10000):
    
    input_layer = exemple

    outputs = sigfunc(np.dot(input_layer, emo_value))

    error = result - outputs

    bigone = largest(emo_value, 3)

    if np.any(error < 0.2):
        error += bigone

    if np.any(error > 0.2):
        error -= bigone

    adjustments = error * sigfunc_derivative(outputs)

    emo_value += np.dot(input_layer.T, adjustments)

print('Poid emotionel apres entraiment = ')
print(emo_value)

print('output = ')
print(outputs)