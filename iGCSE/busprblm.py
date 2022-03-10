from rich.console import Console
from rich.table import Table
import os

console = Console()
prompts = Table(show_header=False)
prompts.add_row("""[yellow]┏ 0[/yellow]. [green]Edit[/green] the [bold]punctuality[/bold] of a bus
[yellow]┃ 1[/yellow]. [cyan]View[/cyan] the [bold]punctuality[/bold] of a bus
[yellow]┃ 2[/yellow]. [cyan]View[/cyan] the average [bold]punctuality[/bold] for each bus 
[yellow]┃ 3[/yellow]. [cyan]View[/cyan] the bus with the highest number of days where it was late]
[yellow]┃ 4[/yellow]. [cyan]View[/cyan] the average lates for a bus on the days it was late"
[yellow]┃ 5[/yellow]. [cyan]View[/cyan] the [bold]punctuality[/bold] on a specific day
[yellow]┃ 6[/yellow]. [red]Exit[/red] the program
""")

def main():
    #The local high school uses buses to transport students to school. There are six bus routes labelled A to F. You have conducted a survey to analyse the [bold]punctuality[/bold] statistics of these buses over a four-week period. The data from the survey are shown in the table.
    table = [
        [
            0, 4, -5, -1, # Monday
            0, 0, 0, 8, # Tuesday
            0, 3, 0, 1, # Wednesday
            2, 4, 3, 1, # Thursday
            2, -2, 4, -2 # Friday  
        ], # Bus A
        [
            0, 2, 1, -1, # Monday
            1, 0, 0, 8, # Tuesday
            0, 0, 0, 1, # Wednesday
            1, 0, 2, -2, # Thursday
            0, 0, 2, -2 # Friday
        ], # Bus B
        [
            2, -2, -2, 1, # Monday
            0, -3, 0, -1, # Tuesday
            -1, -1, 1, -1, # Wednesday
            -1, 0, 1, -1, # Thursday
            -2, 0, 1, 2 # Friday
        ], # Bus C
        [
            1, 2, 0, 0, # Monday
            0, 0, 0, 0, # Tuesday
            0, 0, 0, 0, # Wednesday
            0, 0, 0, 0, # Thursday
            0, 0, 0, 0 # Friday
        ], # Bus D
        [
            -1, -10, 0, 1, # Monday
            -1, -4, 1, 3, # Tuesday
            -1, -2, 2, -1, # Wednesday
            -2, 0, -3, 0, # Thursday
            -4, 0, 1, 0 # Friday
        ], # Bus E
        [
            0, -3, 0, 1, # Monday
            -5, -5, -2, 0, # Tuesday
            -5, 0, -3, 0, # Wednesday
            -5, 0, 1, -2, # Thursday
            -4, 0, 1, -5 # Friday
        ] # Bus F
    ]
    exit = False
    # The [bold]punctuality[/bold] statistics of the buses are shown in the table.

    # Positive numbers represent minutes early, negative numbers represent minutes late and 0 represents the bus having been on time.
    while not(exit):
        os.system('clear')
        console.print("""[magenta]What would you like to do?[/magenta]""")
        console.print(prompts)
        coption = -1

        while True:
            try:
                coption = int(input())
                if coption < 0 or coption > 6:
                    raise ValueError
                break
            except ValueError:
                os.system('clear')
                console.print("""**[magenta]What would you like to do?[/magenta]**

    [yellow]0[/yellow]. [green]Edit[/green] the [bold]punctuality[/bold] of a bus
    [yellow]1[/yellow]. [cyan]View[/cyan] the [bold]punctuality[/bold] of a bus
    [yellow]2[/yellow]. [cyan]View[/cyan] the average [bold]punctuality[/bold] for each bus 
    [yellow]3[/yellow]. [cyan]View[/cyan] the bus with the highest number of days where it was late]
    [yellow]4[/yellow]. [cyan]View[/cyan] the average lates for a bus on the days it was late"
    [yellow]5[/yellow]. [cyan]View[/cyan] the [bold]punctuality[/bold] on a specific day
    [yellow]6[/yellow]. [red]Exit[/red] the program""")

        


def timeinput(prompt): # returns a valid time input as a value between 0-3.
    while True:
        try:
            val = int(input(prompt))
            if val < 1 or val > 4:
                raise ValueError
            return val-1
        except ValueError:
            print("Invalid input, please try again")

def businput(prompt): # returns a valid bus input as a value between A-F
    while True:
        try:
            val = input(prompt)
            if val not in "ABCDEF":
                raise ValueError
            if len(val) > 1:
                raise ValueError
            return val
        except ValueError:
            print("Invalid input, please try again")

def dayinput(prompt): # returns a valid day input.
    while True:
        try:
            val = int(input(prompt))
            if val < 1 or val > 5:
                raise ValueError
            return val-1 # returns the day from 0-4, 0 being monday 4 being friday.
        except ValueError:
            print("Invalid input, please try again")

main()