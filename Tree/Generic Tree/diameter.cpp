//diameter of tree = height of deepest node + height of second deepest node + 2
  static int diameter;

  //in this function we will calculate diameter but return height of deepest child to calcate the deepest and second deepest child in overall tree
  static int calcDiaReturnHeight(Node node) {
      int deepestChild = -1; //initialised as -1 because 0 is a valid height
      int secondDeepestChild = -1;

      for(Node child : node.children) {
          int childHeight = calcDiaReturnHeight(child);

          //update deepest and second deepest child as per the incomng values from children
          if(childHeight > deepestChild) {
              secondDeepestChild = deepestChild;
              deepestChild = childHeight;
          }
          else if(childHeight > secondDeepestChild)
              secondDeepestChild = childHeight;
      }

      //updating diameter
      if(deepestChild + secondDeepestChild + 2 > diameter)
        diameter = deepestChild + secondDeepestChild + 2; // + 2 is done to add the height from the current node one edge on both sides

      deepestChild += 1; //to calculate the height of current node

      return deepestChild;
  }
