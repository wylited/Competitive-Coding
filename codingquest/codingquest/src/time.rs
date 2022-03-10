use std::time::{Instant, Duration};

fn main() {
  let mut fps: u64 = 0;
  let mut last = Instant::now();

  loop {
    fps += 1;

    if (Instant::now() - last) >= Duration::from_secs(1) {
      print!("FPS {}\n", fps);
      fps = 0;
      last = Instant::now();
    }
  }
}