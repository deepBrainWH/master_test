# Machine Learning-1: Liner Regression

## 1. Gradient Descent

Given input datasets: $(x^1, \hat{y}^1), (x^2, \hat{y}^2), ... (x^n, \hat{y}^n)$

Define model function: $f(x) = b + w*x_{cp}$

define loss function of our model $f$: 

$$L(f) = \displaystyle\sum^N_{i=1} (\hat{y}^i - f(x^i))^2 $$

$=\displaystyle\sum^N_{i=1}(y^i - (w*x_{cp}^i + b))^2$

损失函数对$w$求偏导数:

$\frac{\partial L(f)}{\partial w} = -\displaystyle\sum_{i=1}^N 2*(y^i - (w*x_{cp}^i + b)) *x_{cp}^i$

损失函数对$b$求偏导数: 

$\frac{\partial L(f)}{\partial b} = - \displaystyle\sum_{i=1}^N 2*(y^i - (w*x_{cp}^i + b)) * 1.0$

更新$w$ 和 $b$的方法:

$w := w - \eta * \frac{\partial L(f)}{\partial w}$

$b := b - \eta*\frac{\partial L(f)}{\partial b}$

## 2. Regularization

Given the model function: $y = b + \sum w_ix_i$, we add the regularization component in loss function of our model:

$L = \displaystyle\sum_n (\hat{y}^n - (b+\displaystyle\sum w_ix_i))^2 + \lambda\displaystyle\sum(w_i)^2$

> 做regularization时不用考虑bias, 因为bias影响的是函数上下平移, 并不影响函数的平滑程度. 

## 3. Classification Problem

假设每一个类别y中的数据x都符合Gaussian分布$F(x; \mu,\sum)$, 其中$\mu$为x均值向量, $\sum$为x协方差矩阵, 对于n个类别, 有n个Gaussian model, 分别为:$F(x; \mu_1,\sum_1),F(x; \mu_2,\sum_2),..., F(x; \mu_n,\sum_n)$, 要想使得分类器效果最好,定义最大似然函数: $L(\mu, \sum)$, 我们的目标是:

$\mu^*, \sum^* = argmax L(\mu, \sum), given \mu, \sum$

穷举所有$\mu, \sum$, 找到能使$L(\mu, \sum)$最大的$\mu^*, \sum^*$

 

$P(C_i|x) = \frac{P(x|C_i)P(C_i)}{\displaystyle\sum_{u=1}^N P(x|C_u)P(C_u)}$

对于二分类问题, 我们的模型为:

$P(C_1|x) = \frac{P(x|C_1)P(C_1)}{P(x|C_1)P(C_1)+P(x|C_2)P(C_2)}$

$P(C_2|x) = \frac{P(x|C_2)P(C_2)}{P(x|C_1)P(C_1)+P(x|C_2)P(C_2)}$

其中$P(C_i|x)$为均值为$\mu$协方差为$\sum$的Gaussian分布.因此我们训练模型时,对每一类数据要计算出$\mu$和$\sum$, 求解出这个类别的Gaussian分布, 最终得到一个Gaussian model: $F(x;\mu,\sum)$, 输入x到此模型中就会得到一个Gaussian概率, $P(C_i)$比较容易得到, 根据标签就能简单计算出: $P(C_i) = \frac{count(C_i)}{all_class_count}$

关于Gaussian模型的优化: 事实上并不是对每一个类别的Gaussian分布都会求得一个协方差矩阵$\sum$, 而往往是多个类别公用同一个协方差矩阵$\sum$, 每个类别有自己独立的$\mu$, 这个公用的$\sum = \mu_i * \sum_1 + \mu_2 * \sum_2$, 使用公用的covariance matrix有一个好处,就是使得原来的非线性模型变成了一个线性模型. 