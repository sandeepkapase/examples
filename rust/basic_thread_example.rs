use std::thread;
use std::time::Duration;

fn main() {
    let handle = thread::spawn(|| {
        for i in 1..10000001 {
            if i == 10000000 {
            println!("hi number {} !", i);
            }
        }
    });
    handle.join().unwrap();
}
