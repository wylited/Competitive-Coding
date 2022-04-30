use std::fs;

fn main(){
    let data = fs::read_to_string("/home/wylited/Documents/coding/Competitive Programming/codingquest/saab.txt").expect("Something went wrong reading the file");
    let mut space: [Option<i32>; 10000] = [Some(0); 10000];
    for (i, val) in data.lines().enumerate() {
        let mut j = 0;
        while j < 100 {
            space[(i*20)+j] = Some(val.split(" ").nth(j as usize).map(|x| x.parse::<i32>().unwrap()).unwrap());
            j += 1;
        }
    }

    let mut tot: i32 = 0;
    let mut checked: Vec<i32> = Vec::new();

    for i in 0..10000 {
        // Check if space[i] has already been checked
        if checked.contains(&i) { continue; }
        // Check if space[i] is 0
        if space[i as usize].unwrap() == 0 { continue; }

        tot += 1;

        // Make sure that i is within bounds for each if else statement
        if i < 10000 {
            if space[(i+1) as usize] != Some(0) {
                checked.push(i+1);
                checked = check(&space, i+1, checked);
            }
        }
        if i > 0 {
            if space[(i-1) as usize] != Some(0) {
                checked.push(i-1);
                checked = check(&space, i-1, checked);
            }
        }
        if i > 100 {
            if space[(i-100) as usize] != Some(0) {
                checked.push(i-100);
                checked = check(&space, i-100, checked);
            }
        }
        if i < 99900 {
            if space[(i+100) as usize] != Some(0) {
                checked.push(i+100);
                checked = check(&space, i+100, checked);
            }
        }
        // Print out the total amount of checked values
    }
    println!("{} {}", tot, checked.len());
}

fn check(space: &[Option<i32>], i: i32, mut checked: Vec<i32>) -> Vec<i32> {
    //Check if the value is already checked.
    if checked.contains(&i) { return checked; }

    //Check if the value is 0 
    if space[i as usize].unwrap() == 0 { return checked; }

    // Check the values around i and if they have not been checked add them to the checked list and then recursively check if the values around them have been checked.
    if (i+1) < 10000 {
        if space[(i+1) as usize] != Some(0) {
            // Check if i+1 has already been checked.
            if !checked.contains(&(i+1)) {
                checked.push(i+1);
                checked = check(space, i+1, checked);
            }
        } 
    }

    if (i-1) > 0 {
        if space[(i-1) as usize] != Some(0) {
            // Check if i-1 has already been checked.
            if !checked.contains(&(i-1)) {
                checked.push(i-1);
                checked = check(space, i-1, checked);
            }
        }
    }

    if (i+100) < 99000{
        if space[(i+100) as usize] != Some(0) {
            // Check if i+100 has already been checked.
            if !checked.contains(&(i+100)) {
                checked.push(i+100);
                checked = check(space, i+100, checked);
            }
        } 
    }
    if (i-100) > 100 {
        if space[(i-100) as usize] != Some(0) {
            // Check if i-100 has already been checked.
            if !checked.contains(&(i-100)) {
                checked.push(i-100);
                checked = check(space, i-100, checked);
            }
        }
    }
    return checked;
}