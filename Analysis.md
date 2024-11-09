## Analysis

![Plot Results](student_plot.png)

<strong>Question 1: Were you able to generate something close to what the example showed? Why or why not.</strong>

Yes, I was able to generate something close to what the example showed, however it proved to be a bit of a hassle to do so. I guess I learned a few things along the way! I wasn't able to use the github codespaces to create the student plot as the codespace address sanitizer would crash it after a certain period of time. So to solve this issue, I ssh'ed into onyx and ran the code from there. This was the way that I was able to produce the graph without issues and then exported my project back over to my laptop using MobaXTerm. Other than getting it to run I didn't have any trouble modifying the bash script to create the plot and it worked beautiful once I could get it to run. With being able to generate something similar it made me more and more confident in my code of the mergesort_mt and how I structured it. This also heavily leads into being able to complete the rest of the assignment.

<strong> Question 2: Did you see a slow down at some point why or why not? </strong>

Yes, I did see a slow down after the 10th thread with my system being on Windows 11. I think this slow done occurs because as we know there comes a certain point where adding more threads to the program begins to boggle it down and actually makes it slower. So the 11th thread is the limit at which the efficiency as defined within my code reaches its limit and is reflected in the graph. Now you can see that some of the threads actually are a bit faster than the others however, none are as fast as the 10th thread from there on up to 32.

<strong> Question 3: Did your program run faster and faster when you added more threads? Why or why not? </strong>

My program ran faster up to a point. I did notice that sometimes at particular threads would be slightly faster than the one before in which would result in a positive sign being output, however overall the more threads you added over a certain point became ineffective time wise. The more threads that where added eventually just produce in similar time, but not faster time. This influenced the class lectures as we spent time discussing how everyone thought this would work. I think ultimately as with everything this depends on the system that you have and how it allocates and deallocates itself memory as well as handles threads. I think we could see this number be a lot higher say on a quantam computer and its ability to deal with hundreds of threads. But for our machines, they seem to be only able to handle at max 9 to 11 threads before the isn't any significant advantage to doing the program multi-threaded.

<strong> Question 4: What was the optimum number of threads for your machine? </strong>

The optimum number of threads for my machine was 10 on my Windows 11 as after this point the time averages out and no significant benefit is obtained. This result mirrored the result that the Professor had found to be true for his own system which I concurred with the findinds of my own result. Overall, system type systems to be the determinant on how far our machines can take threads.

<strong> Question 5: What was the slowest number of threads for your machine? </strong>

The slowest number of threads for my machine was 1 at 20345.288086 miliseconds.