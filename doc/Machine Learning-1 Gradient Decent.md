# Machine Learning-1: Liner Regression

## 1. Gradient Descent

Given input datasets: $(x^1, \hat{y}^1), (x^2, \hat{y}^2), ... (x^n, \hat{y}^n)$

Define model function: $f(x) = b + w*x_{cp}$

define loss function of our model $f$: 

$$L(f) = \displaystyle\sum^N_{i=1} (\hat{y}^i - f(x^i))^2 $$

$=\displaystyle\sum^N_{i=1}(y^i - (w*x_{cp}^i + b))^2$

损失函数对$w$求偏导数:

$\frac{\partial L(f)}{\partial w} = \displaystyle\sum_{i=1}^N 2*(y^i - (w*x_{cp}^i + b)) *x_{cp}^i$

损失函数对$b$求偏导数: 

$\frac{\partial L(f)}{\partial b} = \displaystyle\sum_{i=1}^N 2*(y^i - (w*x_{cp}^i + b)) * 1.0$

更新$w$ 和 $b$的方法:

$w := w - \eta * \frac{\partial L(f)}{\partial w}$

$b := b - \eta*\frac{\partial L(f)}{\partial b}$

## 2. Regularization

Given the model function: $y = b + \sum w_ix_i$, we add the regularization component in loss function of our model:

$L = \displaystyle\sum_n (\hat{y}^n - (b+\displaystyle\sum w_ix_i))^2 + \lambda\displaystyle\sum(w_i)^2$

> 做regularization时不用考虑bias, 因为bias影响的是函数上下平移, 并不影响函数的平滑程度. 