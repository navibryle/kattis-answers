import sys
if __name__ == "__main__":
    count = 0
    pred = None
    for i in sys.stdin:
        if count == 0:
            stuff = i.split()
            pred = stuff[1]
        else:
            stuff = i.split()
            inTheList = False
            stuff.pop(0)
            for i in stuff:
                if i == pred:
                    inTheList = True
                    break
            if inTheList:
                print("KEEP")
            else:
                print("REMOVE")
        count += 1