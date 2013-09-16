/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2013 Tulipallo.org
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 */
package org.tulipallo.tools.cfd.entity;

import java.util.HashSet;
import java.util.Set;
import junit.framework.TestCase;
import org.junit.Test;

 /**
  * <p>AttributeTest</p>
  * 
  * <p><tt>Tulipallo - The Java Finite Area Method Simulation<br />
  * Copyright &copy; 2013, Tulipallo.org.</tt></p>
  * 
  * <p>For more information on jFVM and other Tulipallo projects please visit
  * <a href="http://www.tulipallo.org">http://www.tulipallo.org</a></p>
  * <p><tt>This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.</tt></p>
  * 
  * <p><tt>You should have received a copy of the GNU General Public License
  * along with this program.  If not, see 
  * <a href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses</a>.</tt></p>
  *
  * @author murrellrr
  * @since Java 6
  * @version 1.0 beta
  */
public class AttributeTest {
    @Test
    public void testConstructorNameNull() {
        try {
            new Attribute(null, new TypeMock());
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected behavior
        }
    }
    
    @Test
    public void testConstructorNameEmpty() {
        try {
            new Attribute("", new TypeMock());
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected behavior
        }
    }
    
    @Test
    public void testConstructorTypeNull() {
        try {
            new Attribute("name", null);
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected behavior
        }
    }
    
    @Test
    public void testConstructorDescriptionNull() {
        try {
            new Attribute("name", new TypeMock(), null);
        }
        catch(Exception e) {
            e.printStackTrace();
            TestCase.fail("Expected description optional.");
        }
    }
    
    @Test
    public void testConstructorDefaultNull() {
        try {
            new Attribute("name", new TypeMock(), null, false, false, false, 
                          null);
        }
        catch(Exception e) {
            e.printStackTrace();
            TestCase.fail("IllegalArgumentException.");
        }
    }
    
    @Test
    public void testConstructorValidatorsNull() {
        try {
            new Attribute("name", new TypeMock(), null, false, false, false, 
                          null, null);
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected behavior
        }
    }
    
    @Test
    public void testConstructorValidatorsEmpty() {
        try {
            new Attribute("name", new TypeMock(), null, false, false, false, 
                          null, new HashSet<Validator>());
        }
        catch(Exception e) {
            e.printStackTrace();
            TestCase.fail("Expected 0 length validators allowed.");
        }
    }
    
    @Test
    public void testConstructor() {
        Object         defaultValue = new Object();
        TypeMock       typeMock     = new TypeMock();
        Set<Validator> validators   = new HashSet<Validator>();
        
        Attribute attribute = new Attribute("name", typeMock, "description", 
                true, true, true, defaultValue, validators);
        
        TestCase.assertEquals("name", attribute.getName());
        TestCase.assertEquals(typeMock, attribute.getType());
        TestCase.assertEquals("description", attribute.getDescription());        
        TestCase.assertTrue(attribute.isNullable());
        TestCase.assertTrue(attribute.isReadOnly());
        TestCase.assertTrue(attribute.isVetoable());
        TestCase.assertEquals(validators, attribute.getValidators());
        TestCase.assertEquals(defaultValue, attribute.getDefaultValue());
    }
    
    @Test
    public void testAddValidatorNull() {
        Attribute attribute = new Attribute("name", new TypeMock());
        
        try {
            attribute.addValidator(null);
            TestCase.fail("Expected IllegalArgumentException.");
        }
        catch(IllegalArgumentException e) {
            // Expected behavior.
        }
    }
    
    @Test
    public void testAddValidator() {
        Attribute attribute = new Attribute("name", new TypeMock());
        Validator validatorMock = new ValidatorMock();
        
        attribute.addValidator(validatorMock);
        
        TestCase.assertTrue(attribute.getValidators().contains(validatorMock));
    }
    
    @Test
    public void testRemoveValidatorNull() {
        Attribute attribute = new Attribute("name", new TypeMock());
        
        try {
            attribute.removeValidator(null);
        }
        catch(Exception e) {
            e.printStackTrace();
            TestCase.fail("Expected passive skip.");
        }
    }
    
    @Test
    public void testRemoveValidator() {
        Attribute attribute = new Attribute("name", new TypeMock());
        Validator validatorMock = new ValidatorMock();
        
        attribute.addValidator(validatorMock);
        attribute.removeValidator(validatorMock);
        
        TestCase.assertFalse(attribute.getValidators().contains(validatorMock));
    }
    
    @Test
    public void testValidateReadOnly() {
        Attribute attribute = new Attribute("name", new TypeMock(), null, 
                true, false, false, null);
        
        try {
            attribute.validate("value");
            TestCase.fail("Expected UnmodifiableAttributeException.");
        }
        catch(UnmodifiableAttributeException e) {
            //
        }
    }
    
    @Test
    public void testValidateNoNullable() {
        Attribute attribute = new Attribute("name", new TypeMock(), null, 
                false, false, false, null);
        
        try {
            attribute.validate(null);
            TestCase.fail("Expected NullAttributeException.");
        }
        catch(NullAttributeException e) {
            //
        }
    }
    
    @Test
    public void testValidateNullable() {
        Attribute attribute = new Attribute("name", new TypeMock(), null, 
                false, true, false, null);
        
        try {
            attribute.validate(null);          
        }
        catch(Exception e) {
            e.printStackTrace();
            TestCase.fail("Expected nullable.");
        }
    }
    
    @Test
    public void testValidateTypeInvalid() {
        Attribute attribute = new Attribute("name", new TypeMock(), null, 
                false, false, false, null);
        
        try {
            attribute.validate(new Double(0.0d));
            TestCase.fail("Expected InvalidAttributeTypeException.");
        }
        catch(InvalidAttributeTypeException e) {
            //
        }
    }
    
    @Test
    public void testValidate() {
        Attribute attribute = new Attribute("name", new TypeMock(), null, 
                false, false, false, null);
        ValidatorMock mockValidator = new ValidatorMock();
        attribute.addValidator(mockValidator);
        
        attribute.validate("test");       
        TestCase.assertTrue(mockValidator.isValidateInvoked());
    }
    
    @Test
    public void testValidateFail() {
        Attribute attribute = new Attribute("name", new TypeMock(), null, 
                false, false, false, null);
        ValidatorMock mockValidator = new ValidatorMock(false);
        attribute.addValidator(mockValidator);
        
        try {
            attribute.validate("test");
            TestCase.fail("Expected ValidationException.");
        }
        catch(ValidationException e) {
            // Expected
        }
        
        TestCase.assertTrue(mockValidator.isValidateInvoked());
    }
}
