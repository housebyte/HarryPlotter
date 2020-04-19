# HarryPlotter
C/C++ Graphing Library Plotting realtime data in X windows with keymapping
Simple X Windows Graphing:

1. Upto 3 traces
2. Easy to implement example provided
3. Additional Key thread feature for manipulating your data on the fly

g++ -I ./ -o keytest_ keytest.cc ./HarryPlotter.so -lpthread -lX11


Caution runfunc counter must begin at zero.
Use sleep(1) within while loop for plotting time.

Useful for plotting any time series in C++ on linux.

Requirements X11-devel , Pthreads

Dont forget to include the *.h files for your plotting projects.

Thanks.

