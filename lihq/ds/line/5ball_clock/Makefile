CFLAGS+=-Wall

all:ball_clock
ball_clock:squeue.o sqstack.o main.o
	$(CC) $^ -o $@ $(CFLAGS)
	
clean:
	rm ball_clock *.o -rf
