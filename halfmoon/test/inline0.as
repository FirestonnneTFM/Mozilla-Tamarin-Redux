/* -*- Mode: actionscript; -*- */

package {

   trace( caller(42) )

   public class vec {
       var x:int;
        var y:int;

        function vec(x:uint,y:uint) {
            this.x=x;
            this.y=y;
        }

        public function toString():String {
            return "x:"+x+" y:"+y;
        }

        public function add(v:vec):vec {
            return new vec(x+v.x,y+v.y);
        }

        public function sum():int {
           return this.x+this.y;
        }

    }//class vec


function caller( p1: int) : int {
   var v:vec = new vec(1,2)
   var rc:int = v.sum()
   //trace(rc)
   return rc
   }

}
   
