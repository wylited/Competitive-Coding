use std::collections::HashMap;
fn main() {

}

fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut seen: HashMap<i32, i32> = HashMap::new();
    for (i, val) in nums.iter().enumerate() {
        let remaining = target - val;
        if seen.contains_key(&remaining) {
            return vec![seen[&remaining], (i as i32)];
        }
        seen.insert(*val, (i as i32));
    }
    return vec![0,0];
}