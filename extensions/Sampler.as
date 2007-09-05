/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package flash.sampler
{
    public final class StackFrame
    {
   	public const name:String;
	public const file:String;
	public const line:uint;
	public function toString():String
	{
		return name + "()" + (file ? "[" + file + ":" + line + "]" : "");
	}
    };
	

    /**
     * The Sample class creates objects that hold memory analysis information over distinct durations.
     * <p><strong>Note:</strong> Only available when using the Flash Player debugger version <em>and</em> when 
     * you have an mm.cfg file containing the line:</p>
     * <pre>AS3AllocationTracking=true</pre>
     * <p>The mm.cfg file is, or can be created, in:</p>
     * <ul><li>Macintosh: HD/Library/Application Support/Macromedia</li>
     * <li>Windows: C:\Documents and Settings\<em>username</em></li>
     * <li>Linux: /home/<em>username</em></li>
     * </ul>      
     * @includeExample examples\MemoryTestExample.as -noswf     
     * @playerversion Flash 9.0.xx.0
     * @langversion 3.0     
     * @keyword Sample      
     * @see flash.profiler#getSamples()
     */
    public class Sample
    {
		/**
	     * The microseconds that define the duration of the Sample instance.
	     * 
	     * @playerversion Flash 9.0.xx.0
	     * @langversion 3.0     
	     * @keyword Sample, Sample.time, time         
		 */
        public const time:Number;

		/**
		 * Contains information about the methods executed by Flash Player over a specified period of time. The format for the 
	     * stack trace is similiar to the content shown in the exception dialog box of the Flash Player debugger version.
	     * @playerversion Flash 9.0.xx.0
	     * @langversion 3.0     
	     * @keyword Sample, Sample.stack, stack     
	     * @see flash.profiler flash.profiler package     
		 */
        public const stack:Array;
    };

    /**
    * Occurs in getSamples() stream when an object is created
    */
    public final class NewObjectSample extends Sample
    {
    	/** 
    	 * Unique id for this object for matching up with DeleteObjectSample's
    	 */
    	public const id:Number;
    	
    	/**
    	 * the Class object corresponding to the object created
    	 */
    	public const type:Class;
    	
    	/**
    	 * get the object if its still live, if its collected this will return
    	 * undefined and a DeleteObjectSample will have been issued.
    	 */
    	public native function get object():*;
   
    };
	
	/**
    * Occurs in getSamples() stream when an object is created
    */
    public final class DeleteObjectSample extends Sample
    {
    	/** 
    	 * Unique id for this object for matching up with NewObjectSample's
    	 */
    	public const id:Number;

	/**
         * size of object right before it was deleted
         */
	public const size:Number;
    };


    /**
     * clear's the current set of samples, usually called after calling getSamples and iterating over 
     * the samples.
     */
	public native function clearSamples():void;


	public native function startSampling():void;

	/**
	 * shutdown sampling and free all its resources, can be started w/ startSampling
	 */
	public native function stopSampling():void;

	/**
	 * momentarily stop sampling, restart using startSampling
	 */
	public native function pauseSampling():void;
	
	/**
	* Returns the size in memory of a specified object when used with the Flash Player debugger version. If 
    * used with a Flash Player that is not the debugger version, this method returns <code>0</code>.
    * <p><strong>Note:</strong> You must have an mm.cfg file containing the line:</p>
    * <pre>AS3AllocationTracking=true</pre>
    * <p>The mm.cfg file is, or can be created, in:</p>
    * <ul><li>Macintosh: HD/Library/Application Support/Macromedia</li>
    * <li>Windows: C:\Documents and Settings\<em>username</em></li>
    * <li>Linux: /home/<em>username</em></li>
    * </ul>    
    * @param o The object to analyze for memory usage.
    * @return The byte count of memory used by the specified object.
    * @includeExample examples\MemoryTestExample.as -noswf      
    * @playerversion Flash 9.0.xx.0
    * @langversion 3.0     
    * @keyword getSize      
	*/
	public native function getSize(o:*):Number;

    /**
     * Returns an object containing all members of a specified object, including private members. You can then 
     * iterate over the returned object to see all values. This method is similar to the flash.utils.describeType() 
     * method but also allows you to see private members and skips the intermediate step of creating an XML object.
     * <p><strong>Note:</strong> Only available when using the Flash Player debugger version <em>and</em> when 
     * you have an mm.cfg file containing the line:</p>
     * <pre>AS3AllocationTracking=true</pre>
     * <p>The mm.cfg file is, or can be created, in:</p>
     * <ul><li>Macintosh: HD/Library/Application Support/Macromedia</li>
     * <li>Windows: C:\Documents and Settings\<em>username</em></li>
     * <li>Linux: /home/<em>username</em></li>
     * </ul>     
     * @param o The object to analyze.
     * @param instanceNames If object is a Class and instanceNames is true report the instance names as if o was an instance of class instead of the class's member names.
     * @return An Object that you must iterate over with a <code>for each..in</code> loop to retrieve the QNames for
     * each property.
     * @includeExample examples\MemoryTestExample.as -noswf       
     * @playerversion Flash 9.0.xx.0
     * @langversion 3.0     
     * @keyword getMemberNames
     * @see flash.utils#describeType()
     * @see ../../statements.html#for_each..in for each..in    
     * 
     */
    public native function getMemberNames(o:Object, instanceNames:Boolean=false):Object;

 
    /**
     * Returns an object of memory usage Sample instances from the last sampling session.
     *
     * @return An iterator of Sample instances.
     * @playerversion Flash 9.0.xx.0
     * @langversion 3.0     
     * @keyword getSamples     
     * @see flash.profiler#Sample
     */
    public native function getSamples():Object;

    /** returns the number of samples piled up */
    public native function getSampleCount():Number;
    
    public function getInvocationCount(obj:Object, qname:QName):Number { return _getInvocationCount(obj, qname, 0); }
    public function getSetterInvocationCount(obj:Object, qname:QName):Number { return _getInvocationCount(obj, qname, 2); }
    public function getGetterInvocationCount(obj:Object, qname:QName):Number { return _getInvocationCount(obj, qname, 1); }

    native function _getInvocationCount(obj:Object, qname:QName, type:uint):Number;

    public native function isGetterSetter(obj:Object, qname:QName):Boolean;
};
