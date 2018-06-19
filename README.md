# cpp-send-udp

I couldn't find any good (simple) examples of how to broadcast to a port via UDP on Windows, so hopefully this helps the next person who goes down this confusing path.

My goal was to get a UWP project to communicate with a Unity program using UDP. UWP added some challenges that made other implementations more challenging, so my goal was to find the simplest implementation that works.

You can confirm that this program is doing the correct thing by downloading and installing WireShark and RawCap.exe.

## To Test

Compile using standard C++ flags, run RawCap.exe (option 5 for localhost) and then run the compiled version of this program.

When the program terminates, close RawCap.exe.

Open the produced .pcap file in WireShark and in the search bar, type "udp.port == 8080" and you will see a single message sent to port 8080 by this program.
