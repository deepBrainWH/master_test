# Gradient tap using guide.
import tensorflow as tf

# 计算一届梯度
def cal_1():
    x = tf.Variable(3.)
    with tf.GradientTape(persistent=True) as tape:
        tape.watch(x)
        y = tf.pow(x, 4)
        dy_dx = tape.gradient(y, x)
        print(dy_dx)
        dy2_dx2 = tape.gradient(y, x)
        print(dy2_dx2)
    del tape

# 计算二阶梯度
def cal_2():
    x = tf.Variable(4.)
    with tf.GradientTape() as tape1:
        tape1.watch(x)
        with tf.GradientTape() as tape2:
            tape2.watch(x)
            y = tf.pow(x, 4)
            dy_dx = tape2.gradient(y, x) # y' = 4x^3
            print(dy_dx)
        dy2_dx2 = tape1.gradient(dy_dx, x) # y'' = 12x^2
        print(dy2_dx2)
    del tape1,tape2

# 计算多个函数的梯度
def cal_3():
    x = tf.Variable(3.)
    with tf.GradientTape(persistent=True) as tape:
        tape.watch(x)
        y = tf.pow(x, 4)        # y = x^4
        z = tf.multiply(x, 3)   # z = 3*x
        dy_dx = tape.gradient(y, x)
        dz_dx = tape.gradient(z, x)
        print(dy_dx)
        print(dz_dx)
    del tape

cal_3()

