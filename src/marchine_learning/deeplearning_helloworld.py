import numpy as np
from tensorflow.keras import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import SGD
from tensorflow.keras.datasets import mnist
from tensorflow.keras import utils

def load_data():
    (x_train, y_train), (x_test, y_test) = mnist.load_data()
    number = 10000
    x_train = x_train[0:number]
    y_train = y_train[0:number]

    x_train = x_train.reshape(number, 28*28)
    x_test = x_test.reshape(x_test.shape[0], 28*28)
    x_train = x_train / 255
    x_test = x_test / 255

    y_train = utils.to_categorical(y_train, num_classes=10)
    y_test = utils.to_categorical(y_test, num_classes=10)

    return x_train,y_train, x_test, y_test


def create_model():
    model = Sequential()
    model.add(Dense(500, input_dim=28*28, activation="sigmoid"))
    model.add(Dense(633, activation="sigmoid"))
    model.add(Dense(512, activation="sigmoid"))
    model.add(Dense(10, activation="softmax"))

    # 定义评估model的好坏 categorical_crossentropy
    model.compile(loss="categorical_crossentropy", optimizer=SGD(learning_rate=0.1),
                  metrics=['accuracy'])
    return model

def fit_model(model, x_train, y_train, x_test, y_test):
    # Training model
    model.fit(x_train, y_train, batch_size=1000, epochs=20)
    model.save(filepath="/home/wangheng/workspace/CLionProjects/master_test/trained_model/")
    # Evaluating the goodness of trained model.
    score = model.evaluate(x_test, y_test)
    print("Total loss on Testing Set: ", score[0])
    print("Accuracy of Testing Set: ", score[1])

    # Predicting the score of trained model
    predict_result = model.predict(x_test)

if __name__ == '__main__':
    x_train, y_train, x_test, y_test = load_data()
    model = create_model()
    fit_model(model, x_train, y_train, x_test, y_test)

