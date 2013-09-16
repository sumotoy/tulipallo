/*
 * Tulipallo - The Java Finite Volume Method Simulation
 * Copyright (C) 2010 M2 Astronautics
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

package org.tulipallo.tools.cfd.scripting;

import java.util.Set;
import org.tulipallo.tools.cfd.entity.Validator;

/**
 * <p/>
 * <tt>Tulipallo - The Java Finite Volume Method Simulation<br />
 * Copyright &copy; 2010 M2 Astronautics</tt>
 * <p/>
 * <tt>This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.</tt>
 * <p/>
 * <tt>You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.</tt>
 *
 * @author Robert R Murrell
 * @since Java 6
 * @version 1.0 beta
 */
public class ScriptedValidator extends Scriptable implements Validator {
    private static final String VARIABLE_VALUE         = "value";
    private static final String VARIABLE_MESSAGES      = "messages";
    private static final String MESSAGE_INVALID_RETURN =
            "No suitable boolean value returned from script.";

    public ScriptedValidator(final RuntimeScript script) {
        super(script);
    }

    @Override
    public boolean validate(final Object value, final Set<String> messages) {
        this.script.put(VARIABLE_VALUE,    value);
        this.script.put(VARIABLE_MESSAGES, messages);
        Object returnValue = this.script.eval();
        if(returnValue == null || !(returnValue instanceof Boolean)) {
            messages.add(MESSAGE_INVALID_RETURN);
            return false;
        }
        else
            return Boolean.class.cast(returnValue).booleanValue();
    }
}
