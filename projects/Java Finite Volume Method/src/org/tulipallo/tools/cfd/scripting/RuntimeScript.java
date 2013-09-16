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

import java.util.Collection;
import java.util.Set;
import javax.script.Bindings;
import javax.script.Compilable;
import javax.script.CompiledScript;
import javax.script.Invocable;
import javax.script.ScriptContext;
import javax.script.ScriptEngine;
import javax.script.ScriptException;
import javax.script.SimpleBindings;

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
public class RuntimeScript {
    private Script         script;
    private ScriptEngine   engine;
    private CompiledScript compiled;
    private Invocable      invocable;
    private Bindings       bindings;

    RuntimeScript(final Script script, final ScriptEngine engine) {
        if(script == null)
            throw new IllegalArgumentException(
                    "Argument \"script\" cannot be null.");
        if(engine == null)
            throw new IllegalArgumentException(
                    "Argument \"engine\" cannot be null.");
        this.script   = script;
        this.engine   = engine;
        this.bindings = new SimpleBindings();
        this.engine.setBindings(bindings, ScriptContext.ENGINE_SCOPE);
        try {
            this.compiled = Compilable.class.cast(engine).compile(
                    script.getCode());
            this.invocable = Invocable.class.cast(engine);
        }
        catch(ScriptException e) {
            throw new ScriptingException(e, script);
        }
    }

    public synchronized <T> T newInstance(final Class<T> anInterface) {
        if(anInterface == null)
            throw new IllegalArgumentException(
                    "Argument \"anInterface\" cannot be null.");
        if(!anInterface.isInterface())
            throw new IllegalArgumentException(
                    "Argument \"anInterface\" must be an interface.");
        if(!anInterface.isAssignableFrom(this.script.implementsInterface()))
            throw new IllegalArgumentException(
                    "Argument \"anInterface\" is not assignable from this " +
                    "scrips implementing interface.");
        return anInterface.cast(this.newInstance());
    }

    public synchronized Object newInstance() {
        if(this.script.implementsInterface() == null)
            throw new IllegalStateException(
                    "No interface implemented.");
        return this.invocable.getInterface(
            this.script.implementsInterface());
    }

    public synchronized Object eval() {
        try {
            return this.compiled.eval();
        }
        catch(ScriptException e) {
            throw new ScriptingException(e, this.script);
        }
    }

    public synchronized Object invoke(final String name, final Object... args) {
        try {
            return this.invocable.invokeFunction(name, args);
        }
        catch(ScriptException | NoSuchMethodException e) {
            throw new ScriptingException(e, this.script);
        }
    }

    public synchronized void put(final String name, final Object value) {
        this.bindings.put(name, value);
    }

    public synchronized Object get(final String name) {
        return this.bindings.get(name);
    }

    public synchronized Object remove(final String name) {
        return this.bindings.remove(name);
    }

    public synchronized Set<String> keys() {
        return this.bindings.keySet();
    }

    public synchronized Collection values() {
        return this.bindings.values();
    }

    public Script getScript() {
        return this.script;
    }

    @Override
    public boolean equals(final Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final RuntimeScript other = (RuntimeScript) obj;
        if (this.script != other.script && (this.script == null ||
                !this.script.equals(other.script))) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 97 * hash + (this.script != null ? this.script.hashCode() : 0);
        return hash;
    }
}
