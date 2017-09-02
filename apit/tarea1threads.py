import threading
import Queue
import sys

def do_work(in_queue, out_queue):
    while True:
        item = in_queue.get()
        # process
        result = item
        out_queue.put(result)
        in_queue.task_done()

if __name__ == "__main__":
    work = Queue.Queue()
    results = Queue.Queue()
    total = 20

    # start for workers
    for i in xrange(4):
        t = threading.Thread(target=do_work, args=(work, results))
        t.daemon = True
        t.start()

    # produce data
    for i in xrange(total):
        work.put(i)

    work.join()

    # get the results
    for i in xrange(total):
        print results.get()

    sys.exit()