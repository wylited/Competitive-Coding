struct Bintree<T> {
    data: T,
    left: Option<Box<Bintree<T>>>,
    right: Option<Box<Bintree<T>>>,
}

fn main() {
    let mut int_vec = vec![1, 5, 10, 2, 15];
    int_vec.sort();
    assert_eq!(int_vec, vec![1, 2, 5, 10, 15]);

    let mut float_vec = vec![1.1, 1.15, 5.5, 1.123, 2.0];

    float_vec.sort_by(|a, b| a.partial_cmp(b).unwrap());

    assert_eq!(float_vec, vec![1.1, 1.123, 1.15, 2.0, 5.5]);

    println!("Hello, world!");
}
