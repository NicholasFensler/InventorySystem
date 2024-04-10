# InventorySystem
//This program was written as a class assignment with certain parameters necessary. 

My approach when writing this program was to use the structure to copy it's data to the file in an organized way so that it may be copied from the file back into a structure for neat input and output between the file and the console output. 
I used a few functions for actions like mostly relating to taking user input and then for output. For simplicities sake as well as time I did not use any functions to read or write to the file and kept them in main.

When using this program it's fairly straight forward, Use character input to select one of the menu options. When inputting data follow the directions by inputting one piece of data at a time. 

Boundries are set in certain places including when setting the date, you cannot enter a larger day than 31, a month of 12, or a year earlier than 2024 (time of making). The program will continue to ask you for that piece of data if it's given a value bigger/smaller than those.
there are also Boundries that keep you from setting the costs of items below 0 as well as the quantity on hand of the item. 

Other notes: When checking for an item that already exists case sensitivity matters. 
When editing you will be required to replace all data about that item. Whether the data is different from previously does not matter but it will ask you to enter all of data for said item when editing. 




