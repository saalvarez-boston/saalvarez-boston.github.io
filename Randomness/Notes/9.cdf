
CS244, Randomness and Computation


:00
Reminders

	PS5 due tonight

		office hours 1:30-3

	I'll return exam 1 papers at the end of today's class meeting


:02
Exam 1 comments (show on screen)


	1) Setting up sample space S with equally likely outcomes, event E:

	nothing random about the sample space - it's just a set
	(randomness enters in selecting outcomes from S)

		wrong to say S = randomly selected numerical digits, 0-9

		correct to say S = all numerical digits, 0-9

	also, sample space S and event E are not numbers

		wrong to say S = 26!/20! for length6 permutations of letters

		correct to say |S| = 26!/20!

	finally, 0 is divisible by 3

		target event in part a is E = {0,3,6,9} 


	2b) Find number of [1 0 1] irows in 1000 x 3 matrix of 1s and 0s

		MATLAB won't allow findstr on multiple rows

			can't do findstr(tosses, [1 0 1])

		Operate on individual columns instead:

			tosses(:,1)==1 & tosses(:,2)==0 & tosses(:,3)==1

		by the way, can also use boolean operators instead of ==

			tosses(:,1) & ~tosses(:,2) & tosses(:,3)
		

	3b) Permutations do not contain repeated letters

	3c) There are two possibilities for three equal toss results: HHH, TTT


	4ab) Considering copies of same letter as distinct will double-count

		there aren't 5! different length-5 words with 2 As, 2 Ts, 1 E

		two As are interchangeable (same word), same for two Ts

		correct answer requires dividing 5! by 2!*2! for permutations

		direct solution: choose 2 of 2 slots for As, then 2 of 3 for Ts

	4c) Binomial expansion of (5-4)^120 = 1^120 = 1


	5) Must be careful with sample spaces and probability distributions

		basic sample space is {xyz | each of x,y,z is c or b}

		with equally likely outcomes

	5c) If it is known that at least one is correct, then bbb eliminated

		probability is uniformly distributed over remaining outcomes

		P(ccc | not bbb) = 1/7

	5b) If randomly selected program inspected, buggy, what's P(1 of 2 b)?

		ccc eliminated, and 7 outcomes left

			need precisely 2 bs

			of 7 outcomes left, bbc, bcb, cbb favorable

			P(1 of 2 others also b | random one b) = 3/7

			right? wrong!
	
		why is this wrong?

			one way to understand: you inspected a specific one

			not the same as eliminating an unspecified c

			another way to understand: nonuniform distribution!

			if one program known buggy, P(bbb) double what it was

		correct analysis: use independence of tosses

			list the inspected program first: b--

			there are 4 equally likely outcomes left: 

				bbb, bbc, bcb, bcc

			probability exactly one other buggy = 2/4 = 1/2


:32
Recently: random variables, expected value

	A RV is a function defined on the sample space of a random experiment

		X: S -> set of variable's values

	Distribution of a RV is the set of probability values of its outcomes

		For each possible value v, P(X=v) = P( {s in S | X(s)=v} )

	For continuous RV, use PDF instead:

		P(X in dx-interval at x) = f(x) dx

		P(a <= X <= b) = int_a^b f(x) dx

	Two common discrete RV distributions

		Binomial	P(X=k) = nCk p^k (1-p)^(n-k)

		Geometric	P(X=k) = p^(k-1) (1-p)

	Expected value of a random variable is its expected average value

		E(X) = p1 v1 + p2 v2 + ... + pi vi + ...


:37
Expected value is linear

	If X and Y are RV, and if a and b are constant numbers, then

		E(aX + bY) = aE(X) + bE(Y)

	This provides an alternative route to calculating expected values


:40 (skip, leave for HW or by e-mail)
Another common discrete RV distribution: Poisson model of arrivals

	X counts arrivals per unit time (service requests, customers, packets),
        assuming arrival probability lambda*dt in each infinitesimal interval dt

        Approximate as binomial RV with very large n, very small p = lambda/n

                P(X=k) = nCk p^k (1-p)^(n-k)

        Only smaller values of k will have considerable probability, so:

                nCk = n^k / k! (approx.)

        and

                (1-p)^(n-k) = (1-p)^n = (1-lambda/n)^n = e^(-lambda) (approx.)

        Therefore, probability of exactly k arrivals in [0,1] is approximately:

                P(X=k) = e^-lambda lambda^k / k!   (all non-negative integers k)

        Note that the sum of all of these P(k) is 1


:40
Cumulative distribution function (CDF) of a RV

	Applies to both discrete and continuous RV

	Is the "running total" of the probability mass distribution of a RV

	Let X:S -> numbers be a RV on S, with PMF p:set of values -> [0,1]

	The CDF of X is F_X:real numbers -> [0,1] defined by:

		F_X(x) = P(X <= x) = sum of P(v) for all v <= x

		use integral instead of sum for continuous RV


:43
Properties of the CDF

	If F is the CDF for some numerical RV, then:

		1) F is monotone increasing, i.e., if a<b then F(a)<=F(b)

		2) F is zero at -infty

		3) F is 1 at +infty

	The CDF is a monotone increasing function

	It would be nice to say that any F with these properties is a CDF,
	but notice that if F is the CDF for a discrete RV, then also:

		D) F is piecewise constant, and jumps at the
		points which represent values of the RV


:48
Example of CDF

	X = sum on two dice

	Set of possible values of X = {2,3,4,5,6,7,8,9,10,11,12}

	PMF: P(X=i) = (6 - |i-7|) / 36

	Plot in MATLAB

		>> probs = (6 - abs((1:13) - 7))/36;
		>> plot(1:13, probs);

	Compute CDF in MATLAB, on, say [1,13]:

		>> cprobs = cumsum(probs);
		>> plot(1:13, cprobs);

	By the way, one can show that:

		F_X(i) = sum_{j<=i} P(X=j) 
		= i(i-1)/72, for i<=7
		= 1 - (i-12)(1-13)/72, for i>=7


:55
Generation of pseudorandom numbers with prescribed distribution

	Given a RV X with distribution f_X, how to simulate samples of X?

	One option: find phi such that phi(rand) has distribution f_X
		(see a recent problem set for an example)

		PDF of phi(rand) is 1 / phi'(phi^-1(y))

		must solve equation 1 / phi'(phi^-1(y)) = f_X(y)

		that isn't always easy to do

	It would be nice to have a systematic technique

		what if you had a function y = g(x) such that

		dy gets mapped back through g to dx such that P_X(dx) = dy ?

		then you could generate samples of X as follows:

			use rand to generate y

			output value x such that g(x) = y

		Well, the CDF is precisely the g that you need!


:60
CDF generation of RV samples with prescribed distribution

	Let F_X be the CDF corresponding to f_X, i.e., 

		F(x) = P(set of all values <= x)

	Imagine that a particular x0 satisfies

		F(x0) = 0.7

	We would like our pseudorandom generator to satisfy:

		P(generated value <= x0) = 0.7

	Assume that a generator for a uniform distribution on [0,1] is available

	We know P(uniformly distributed value is in [0,0.7]) = 0.7

	So, we just make each value in [0,0.7] correspond to a value in [0,x0]

		the endpoint 0.7=F(x0) goes to x0

		more generally, each point F(x) goes to x

		in other words, each point y goes to F^-1(y)


:65
Examples of pseudorandom number generation with a prescribed distribution

	Use randGiven function, to be implemented in PS6


:if time allows
Measuring the variation of a random variable

	Consider the number of heads in 100 tosses of a fair coin

	(do MATLAB simulation of multiple samples of this RV)

	for i=1:100
		hist( sum(randi(2,10^4,10^2)-1, 2) );
		axis([20 80 0 3600]);
		pause(0.1);
	end

	The average number of heads is around 50, which is the expected value

	However, there is considerable variation in the observed average

	In fact, the observed distribution is about 10 units wide at half height

	Another way of viewing this is as a plot instead of a histogram

	We'd like to provide a measure of such variation


:if time allows
Linear variance

	Average of large number of observations of RV X, corresponding to many 
	repetitions of underlying random experiment, is near expected value E(X)

	Variation of X measured by deviation of individual values from average

	You can try the plain deviations from E(X):

		deviation of v = (v - E(X))

	and use expected average of deviations (X) as measure of variation:

		linvar(X) = sum p_i (v_i - E(X))

	Exercise: compute the numerical value of this measure explicitly


:next time
Variance

	As an alternative, it is customary to consider squared deviations

		squared deviation of v = (v - E(X))^2

	The variance of a RV, X, is defined as the expected average of these 
	squared deviations of X from the expected (average) value of X

		var(X) = expected average of (X - E(X))^2

			= sum p_i (v_i - E(X))^2

	Thus, the variance is the expected value of a new RV, (X - E(X))^2

	The more variation X displays, the larger the variance of X

	Before getting into calculation details, note that the variance is
	an average squared distance, not a distance

	To get a measure of the variation of X on the same scale as X,
	just take the square root of the variance, which is what is
	called a root mean square (RMS) measure

	
:next time
Formula for the variance

	How to compute this expected average squared deviation?

	Proceed as we did for the expected value last time

	In a large sample of values of X, the various possible values vi will 
	be represented in proportion to their probabilities, with approximately 
	pi n instances of vi, where n is the total number of samples

	Therefore, expected contribution of vi to sum of squared deviations is
	
		pi n (vi - E(X))^2

	The expected average of all of the vi is the sum divided by n:

		var(X) := sum of pi (vi - E(X))^2

	The more variation X displays, the larger the variance of X


:next time
Variance in terms of the expected values of X and X^2

	The following formula is often useful:

		var(X) = E(X^2) - E(X)^2

	Here's a derivation:

		var(X) = sum of pi (vi - E(X))^2

			= sum of pi (vi^2 + E(X)^2 - 2viE(X))

			= sum of pi vi^2 + E(X)^2 sum of pi - 2E(X) sum of pi vi

			= E(X^2) + E(X)^2 - 2E(X)^2

			= E(X^2) - E(X)^2


:if time allows
Examples of variance calculations

	1) Single Bernoulli trial: suppose P(success)=p, and let X=1 if success,
	X=0 if not success. Then:

		E(X) = p*1 + (1-p)*0 = p

	Also, X^2 is the same as X here, so E(X^2) = p as well

	Therefore,

		var(X) = E(X^2) - E(X)^2 = p - p^2 = p(1-p)

	Plot as function of p - greatest variance / uncertainty at p=1/2

	2) Poisson arrivals: let X = # of arrivals in unit time, 
	for mean arrival rate lambda

	Distribution of X is: 

		P(X=k) = lambda^k/k! e^(-lambda)

	Expected value:

		E(X) = sum_(k>=1) e^(-lambda) lambda^k/(k-1)!

			= lambda sum_{j>=0} e^(-lambda) lambda^j / j!

	The sum is 1, though, because it is the sum of all of the
	values of a Poisson distribution, so:

		E(X) = lambda, the mean arrival rate (of course!)

	Now the variance:

		var(X) = E(X^2) - E(X)^2

	Compute the first term on the right:

		E(X^2) = sum_(k>=1) e^(-lambda) lambda^k/(k-1)! k

			= lambda sum_{j>=0} e^(-lambda) lambda^j / j! (j+1)

	Split into two sums, which have values lambda E(X) and lambda*1, so:

		E(X^2) = lambda^2 + lambda

	and

		var(X) = E(X^2) - E(X)^2 = lambda^2 + lambda - lambda^2 = lambda


:if time allows
Properties of expected value and variance

	Expected value is linear: 

		E(aX + bY) = aE(X) + bE(Y)

	Variance is quadratic, and produces interaction terms: 

		var(X + Y) = var(X) + var(Y) + 2(E(XY) - E(X)E(Y))


:next time
Independent random variables

	RV's X and Y are called independent if all pairs of events

		{X=v} and {Y=w}

	are independent.

	Thus, if X and Y are independent, then for any values v, w:

		P(X=v and Y=w) = P(X=v)*P(Y=w)

	If X and Y are independent, then E(XY) splits:

		E(XY) = sum_{i,j} pi qj vi wj = E(X)E(Y)

	and the variance of X+Y is just the sum of their variances:

		var(X + Y) = var(X) + var(Y)


:next time
Example

	Let X be the number of successes in n independent Bernoulli trials
	with success probability p

	For each i between 1 and n, let Xi be the binary success variable for 
	the i-th trial, with Xi=1 if i-th trial yields a success, 0 otherwise

	Then

		X = sum of all of the Xi

	Furthermore, the Xi are mutually independent, and therefore:

		var(X) = sum of var(Xi) = np(1-p)

	This means that the variation, or uncertainty, in the total number
	of successes, increases as the number of trials increases

	In terms of the expected variation in normal (not quadratic) units,
	we consider instead the standard deviation:

		stdev(X) = sqrt(var(X)) = sqrt(p(1-p))sqrt(n)

	This root mean square distance from the expected value varies
	like the square root of the number of trials

