
import math;

def fmt(value):
    return "%.3f" % value

period = 40
radius = 1.5
timestep = 0.1
maxtime = period*1
z = -1

with open('HelixUpDownNoFF.txt', 'w') as the_file:
    t=0;
    while t <= maxtime/2:
        x = math.sin(t * 2 * math.pi / period) * radius;
        y = math.cos(t * 2 * math.pi / period) * radius; 
        the_file.write(fmt(t) + "," + fmt(x) + "," + fmt(y) + "," + fmt(z) + "\n");
        t += timestep;
        z -= 0.01
    while t>maxtime/2 and t <= maxtime:
        x = math.sin(t * 2 * math.pi / period) * radius;
        y = math.cos(t * 2 * math.pi / period) * radius; 
        the_file.write(fmt(t) + "," + fmt(x) + "," + fmt(y) + "," + fmt(z) + "\n");
        t += timestep;
        z += 0.01
